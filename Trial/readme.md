# Self Note

RMQ_segment_tree.cpp was not giving the desired result when used on the [LCA](https://www.spoj.com/problems/LCA/) problem of spoj. The result was always a segmentation fault. 

It might be the case that the RMQ algo itself has bugs that's why the LCA algo is not working. 

Therefore the critical files are:
- RMQ/segment_tree.cpp 
- RMQ/segment_tree_indexing.cpp 
- Trial/RMQ_segment_tree.cpp
