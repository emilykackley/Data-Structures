#include "digraph.h"
#include <vector>

using namespace std;

template <class T, unsigned int N>
DirectedGraph<T,N>::DirectedGraph()
{
    m_size = N;
    adjMat.resize(N,vector<int>(N,0));
    m_data.resize(m_size);
}

template <class T, unsigned int N>
void DirectedGraph<T,N>::clear()
{
    m_size = 0;
    m_data.clear();
    adjMat.clear();
}

template <class T, unsigned int N>
bool DirectedGraph<T,N>::find(const T& x) const 
{
    for(int i=0; i<m_size; i++)
    {
        if(m_data[i] == x)
          return true;
    }
    return false;
}

template <class T, unsigned int N>
void DirectedGraph<T,N>::addEdge(const unsigned int i, const unsigned int j, const int w)
{
    if( i>= m_size|| j>=m_size)
        throw std::out_of_range("Out of range");
    adjMat[i][j] = w;
}

template <class T, unsigned int N>
void DirectedGraph<T,N>::removeEdge(const unsigned int i, const unsigned int j)
{
    if(i>=m_size || j>= m_size)
        throw std::out_of_range("Out of range");
    adjMat[i][j]=0;
}

template <class T, unsigned int N>
bool DirectedGraph<T,N>::isEdge(const unsigned int i, const unsigned int j) const
{
    if(i>=m_size || j >= m_size)
        throw std::out_of_range("Out of range");
    if(adjMat[i][j] >0)
        return true;
    return false;
}

template <class T, unsigned int N>
int DirectedGraph<T,N>::getEdgeWeight(const unsigned int i, const unsigned int j) const
{
    if(i>=m_size || j>=m_size)
        throw std::out_of_range("out_of_range");
    return(adjMat[i][j]);
}

template <class T, unsigned int N>
void DirectedGraph<T,N>::setEdgeWeight(const unsigned int i, const unsigned int j, const int w)
{
    if(i>=m_size || j>= m_size)
        throw std::out_of_range("out_of_range");
    adjMat[i][j] = w;
}

template <class T, unsigned int N>
T DirectedGraph<T,N>::getVertexData(const unsigned int i) const 
{
    if(i>=m_size)
        throw std::out_of_range("Out of range");
    return(m_data[i]);
}

template <class T, unsigned int N>
void DirectedGraph<T,N>::setVertexData(const unsigned int i, const T& data)
{
    if(i>=m_size)
        throw std::out_of_range("Out of range");
    m_data[i]=data;
}

template <class T, unsigned int N>
int DirectedGraph<T,N>::vertexInDegree(const unsigned int i) const 
{
    int count=0; 
    if(i>=m_size)
        throw std::out_of_range("Out of range");
    for(int x=0; x<m_size; x++)
    {
        if(isEdge(x,i))
            count++;
    }
    return count;
}

template <class T, unsigned int N>
int DirectedGraph<T,N>::vertexOutDegree(const unsigned int i) const 
{
    int count=0;
    if(i>=m_size)
        throw std::out_of_range("Out of range");
    for(int x=0; x<m_size; x++)
    {
        if(isEdge(i,x))
            count++;
    }
    return count;
}

template <class T, unsigned int N>
int DirectedGraph<T,N>::graphDegree() const 
{
    int count =0;
    for(int i=0; i<m_size; i++)
    {
        count = count + vertexInDegree(i) + vertexOutDegree(i);
    }
    return count;
}

template <class T, unsigned int N>
bool DirectedGraph<T,N>::isSimple() const
{
    for(int i=0; i<m_size; i++)
    {
        for(int j=0; j<m_size; j++)
        {
            if(isEdge(i,j)&&(isEdge(j,i)))
                return true;
        }
    }
}

template <class T, unsigned int N>
void DirectedGraph<T,N>::bfs(const unsigned int start, int visited[]) const 
{
    if(start>m_size)
        throw std::out_of_range("Out of range");
    for(int i=0; i<N; i++)
        visited[i] =- 1;
    queue<int> q;
    visited[start]=0;
    q.push(start);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int w=0; w<m_size; w++)
        {
            if(isEdge(u,w))
            {
                if(visited[w]==-1)
                {
                    visited[w] = visited[u]+1;
                    q.push(w);
                }
            }
        }
    }
}

template <class T, unsigned int N>
void DirectedGraph<T,N>::dfs(const unsigned int start, int visited[]) const 
{
    int count =0;
    for (int i=0; i< N; i++)
        visited[i]=-1;
    recursiveDfs(start,visited,count);
}

template <class T, unsigned int N>
void DirectedGraph<T,N>::recursiveDfs(unsigned int start, int visited[], int count) const
{
    if(start>=m_size)
        throw std::out_of_range("Out of range");
    visited[start]= count;
    for(unsigned int j=0; j<m_size; j++)
    {
        if(isEdge(start,j))
        {
            if(visited[j==-1])
            {
                recursiveDfs(j,visited,count+1);
            }
        }
    }
}
