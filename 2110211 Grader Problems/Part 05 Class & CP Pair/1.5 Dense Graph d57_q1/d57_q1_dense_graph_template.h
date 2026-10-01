#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
using namespace std;
class DenseGraph{
public:
    // Note : Dense Graph is directed graph 
    DenseGraph() {
        // Your code here
        n = 3 ; // number of vertex 

        // no edges connected to vertex
        adjacency_matrix = vector<vector<bool>>( n , vector<bool>(n,false) ) ; // matrix nxn with false (row n , col n) 
    }

    DenseGraph(int n_in) {
        // Your code here
        n = n_in ; 
        adjacency_matrix = vector<vector<bool>>( n , vector<bool>(n,false) ) ; // matrix nxn with false (row n , col n) 
    }

    DenseGraph(const DenseGraph& G) {
        // Your code here

        // copy number of vertex & adj. graph 
        n = G.n ; 
        adjacency_matrix = G.adjacency_matrix  ; 
    }

    void AddEdge(int a, int b) {
        // Your code here
        adjacency_matrix[a][b] = true ; 

    }

    void RemoveEdge(int a, int b) {
        // Your code here
        adjacency_matrix[a][b] = false ; 
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here

        // loop check if a->b exist
        if (adjacency_matrix[a][b] == true) return true ; 
        return false ; // if not found


    }

    DenseGraph Transpose() const {
        // Your code here

        DenseGraph transposed_adj_matrix(n) ; // create dense graph

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) { 
                transposed_adj_matrix.adjacency_matrix[j][i] = this->adjacency_matrix[i][j] ; 
            }
        }

        return transposed_adj_matrix ; 

    }

protected:
    int n;
    // Your code here

    // create adjacency matrix for storing if that vertex have connected with another vertex
    vector<vector<bool>> adjacency_matrix ;  
};
#endif // __DENSE_GRAPH_H__
