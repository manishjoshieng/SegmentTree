#include "../include/SegmentTree.h"
#include<algorithm>


void 
SegmentTree::build(const vector<int>& array){
    int size = array.size();
    if(size==0) return ;
    cout<<"Tree is getting build...\n";
    // vector<long int> commulativeArray(size);
    // long int curSum = array[0];
    // commulativeArray[0] = curSum;
    // for(int i=1;i<size; i++){
    //     commulativeArray[i] = commulativeArray[i-1]+ array[i];
    // }
    _root = buildInternal(array,0,size);
}


unique_ptr<SegmentTree::Node>
SegmentTree::buildInternal(const vector<int>& array,int start, int end){
    if(start > end) return nullptr;

    unique_ptr<Node> node = make_unique<Node>(0,start,end);

    if(end==start){
        node->_isLeafNode = true;
        node->_sum = array[start];
        return node;
    }

    int mid = start + (end-start)/2;
    
    node->_leftChild = buildInternal(array,start, mid);
    node->_rightChild = buildInternal(array,mid+1,end);
    node->_sum = node->_leftChild->_sum + node->_rightChild->_sum;
    return node;
}

long int 
SegmentTree::query(int start, int end){
    if (start < 0 || end  < 0){
        cout<<"Invalid query\n";
        return -1;
    }

    if(_root==nullptr) {
        cout<<"Tree is not present\n";
    }

    if(_root->_endIndex < end) end = _root->_endIndex;


    return queryInternal(start,end, _root);
}

long int
SegmentTree::queryInternal(int start, int end, const unique_ptr<Node>& root){
    if(root==nullptr) return 0;

    if(root->_startIndex == start && root->_endIndex == end) return root->_sum;
    
    if(root->_leftChild->_endIndex >= end) return queryInternal(start,end,root->_leftChild);
    if(root->_rightChild->_startIndex <= start) return queryInternal(start,end,root->_rightChild);

    long int sum = 0;
    sum += queryInternal(start, root->_leftChild->_endIndex, root->_leftChild);
    sum += queryInternal(root->_rightChild->_startIndex,end, root->_rightChild);

    return sum;
}

void
SegmentTree::updateData(int index, int newData){
    if (_root==nullptr) return;
    updateDataInternal(index,newData,_root);
}

void
SegmentTree::updateDataInternal(int index, int newData, unique_ptr<Node>& root){
    if(root->_isLeafNode && root->_startIndex==index){
        root->_sum = newData;
        return;
    }

    if(root->_leftChild->_endIndex >=  index) updateDataInternal(index,newData, root->_leftChild);
    else updateDataInternal(index,newData, root->_rightChild);

    root->_sum = root->_leftChild->_sum + root->_rightChild->_sum;
}