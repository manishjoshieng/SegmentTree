#pragma once

#include<vector>
#include<iostream>
#include<memory>

using namespace std;

//This tree allow to query a range to find the sum of specific subarray
class SegmentTree{
    public:
        SegmentTree():_root(nullptr){}

        void build(const vector<int>& array);

        long int query(int start, int end);

        void updateData(int index, int newData);

    private:

        struct Node {
            long int            _sum;
            int                 _startIndex;
            int                 _endIndex;
            bool                _isLeafNode;
            unique_ptr<Node>    _leftChild;
            unique_ptr<Node>    _rightChild;

            Node(int sum, int start,int end)
            :_sum(sum),
            _startIndex(start),
            _endIndex(end),
            _isLeafNode(false),
            _leftChild(nullptr),
            _rightChild(nullptr)
            {}
        };

        unique_ptr<Node> buildInternal(const vector<int>& arr, int start, int end);

        long int queryInternal(int start, int end, const unique_ptr<Node>& root);

        void  updateDataInternal(int index, int newData, unique_ptr<Node>& root);


        //Data
        unique_ptr<Node>    _root;
};