cmake_minimum_required(VERSION 3.15)
project(Data_Structure_Cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(Data-Structure-Cpp)
include_directories(Data-Structure-Cpp/00.BasicTools)
include_directories(Data-Structure-Cpp/01.Sort&Search)
include_directories(Data-Structure-Cpp/02.LinkedList)
include_directories(Data-Structure-Cpp/03.BinaryTree)
include_directories(Data-Structure-Cpp/04.Graph)
include_directories(Data-Structure-Cpp/05.Advanced)

add_executable(Data_Structure_Cpp
        Data-Structure-Cpp/00.BasicTools/basic.h
        Data-Structure-Cpp/01.Sort&Search/Exercise00_SortTools.h
        Data-Structure-Cpp/01.Sort&Search/Exercise01_SelectionSort.h
        Data-Structure-Cpp/01.Sort&Search/Exercise02_BubbleSort.h
        Data-Structure-Cpp/01.Sort&Search/Exercise03_InsertionSort.h
        Data-Structure-Cpp/01.Sort&Search/Exercise04_HeapSort.h
        Data-Structure-Cpp/01.Sort&Search/Exercise05_MergeSort.h
        Data-Structure-Cpp/01.Sort&Search/Exercise06_QuickSort.h
        Data-Structure-Cpp/01.Sort&Search/Exercise07_BinarySearch.h
        Data-Structure-Cpp/01.Sort&Search/main_sort.h
        Data-Structure-Cpp/02.LinkedList/Exercise00_ListTools.h
        Data-Structure-Cpp/02.LinkedList/Exercise01_ReverseLinkedList.h
        Data-Structure-Cpp/02.LinkedList/Exercise02_ListPartition.h
        Data-Structure-Cpp/02.LinkedList/Exercise03_ListDuplicate.h
        Data-Structure-Cpp/02.LinkedList/Exercise04_DoublePointer.h
        Data-Structure-Cpp/02.LinkedList/main_list.h
        Data-Structure-Cpp/03.BinaryTree/Exercise00_TreeTools.h
        Data-Structure-Cpp/03.BinaryTree/Exercise01_RecurTraversal.h
        Data-Structure-Cpp/03.BinaryTree/Exercise02_UnrecurTraversal.h
        Data-Structure-Cpp/03.BinaryTree/Exercise03_TreeDP.h
        Data-Structure-Cpp/03.BinaryTree/main_tree.h
        Data-Structure-Cpp/04.Graph/Exercise00_Edge.h
        Data-Structure-Cpp/04.Graph/Exercise00_Graph.h
        Data-Structure-Cpp/04.Graph/Exercise00_GraphTools.h
        Data-Structure-Cpp/04.Graph/Exercise00_Node.h
        Data-Structure-Cpp/04.Graph/Exercise01_BFS.h
        Data-Structure-Cpp/04.Graph/Exercise02_DFS.h
        Data-Structure-Cpp/04.Graph/Exercise03_TopologySort.h
        Data-Structure-Cpp/04.Graph/Exercise04_Kruskal.h
        Data-Structure-Cpp/04.Graph/Exercise05_Prim.h
        Data-Structure-Cpp/04.Graph/Exercise06_Dijkstra.h
        Data-Structure-Cpp/04.Graph/main_graph.h
        Data-Structure-Cpp/05.Advanced/Exercise01_Trie.h
        Data-Structure-Cpp/05.Advanced/Exercise02_UnionFind.h
        Data-Structure-Cpp/05.Advanced/Exercise03_KMP.h
        Data-Structure-Cpp/05.Advanced/Exercise04_Manacher.h
        Data-Structure-Cpp/05.Advanced/Exercise05_SlidingWindow.h
        Data-Structure-Cpp/05.Advanced/Exercise06_MonotonousStack.h
        Data-Structure-Cpp/05.Advanced/Exercise07_MorrisTraversal.h
        Data-Structure-Cpp/05.Advanced/main_advanced.h
        Data-Structure-Cpp/main.cpp)
