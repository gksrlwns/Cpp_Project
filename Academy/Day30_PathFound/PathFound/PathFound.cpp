#include "pch.h"
#include <iostream>
#include "Graph.h"
#include <stack>
#include <queue>

using namespace std;

//------------------------------
//  코딩테스트용
//------------------------------
int vertexSize = 8;
// 1. 정점 (인덱스가 곧 정점입니다.)
vector<bool> visited(vertexSize, false);

// 2. 간선
vector<vector<bool>> edges = vector<vector<bool>>(vertexSize, vector<bool>(vertexSize, 0));


// 이문제 핵심은
//  1. 도착판별
//  2. 갈수있는 노드를 어떻게 체크할건지
//  3. 간선체크를 어떻게할건지

// DFS의 핵심은
//   그래서 갈수있냐예요
//   절대로 가장 깔끔하게 가는방법이 아닙니다.

// 시간복잡도 측면에서는
// O(n)
bool CalulatePath_DFS(int startNode, int endNode)
{
    // 1. 내가 갈수있는 곳을 예약정점으로 만든다.
    stack<int> s;
    s.push(startNode);

    // 2. 예약정점이 존재하는 한 반복한다.
    while (false == s.empty())
    {
        // 현재위치(current)를 다음 예약 정점으로 이동시킨다.
        int current = s.top();
        s.pop();

        // 도착판별
        if (current == endNode)
        {
            printf("연결되어있습니다.\n");
            return true;
        }

        // 해당 정점을 방문했다고 체크
        visited[current] = true;

        // 내가 갈수있는 곳을 모두 예약정점으로 만든다.
        for (int i = 0; i < vertexSize; i++)
        {
            //1. 연결되어 있어야한다.
            //2. 지나간 노드는 예약정점에 못넣는다.
            if (edges[current][i] == true && visited[i] == false)
            {
                s.push(i);
            }
        }
    }

    return false;
}

bool CalulatePath_DFS_Recursive(int current, int endNode)
{
    //1. 방문노드 false체크
    visited[current] = true;

    //2. 내가 갈수있는 노드 재귀돌기
    for (int i = 0; i < vertexSize; i++)
    {
        if (visited[i] == false && edges[current][i] == true)
        {
            CalulatePath_DFS_Recursive(i, endNode);
        }
    }

    return false;
}

bool CalulatePath_DFS_RecursiveRoot(int startNode, int endNode)
{
    //1. 스타트노드로 움직여봐.
    return CalulatePath_DFS_Recursive(startNode, endNode);
}

bool CalulatePath_BFS(int startNode, int endNode)
{
    // 1. 내가 갈수있는 곳을 예약정점으로 만든다.
    queue<int> q;
    q.push(startNode);

    // 2. 예약정점이 존재하는 한 반복한다.
    while (false == q.empty())
    {
        // 현재위치(current)를 다음 예약 정점으로 이동시킨다.
        int current = q.front();
        q.pop();

        // 도착판별
        if (current == endNode)
        {
            printf("연결되어있습니다.\n");
            return true;
        }

        // 해당 정점을 방문했다고 체크
        visited[current] = true;

        // 내가 갈수있는 곳을 모두 예약정점으로 만든다.
        for (int i = 0; i < vertexSize; i++)
        {
            //1. 연결되어 있어야한다.
            //2. 지나간 노드는 예약정점에 못넣는다.
            if (edges[current][i] == true && visited[i] == false)
            {
                q.push(i);
            }
        }
    }

    return false;
}

int main()
{
    //Graph g = Graph::MakeGraph(4);
    
    // 3. 그래프완성 (간선연결) (정점은 1~8이 아니라, 0~7사용합니다.)
    edges[0][1] = true;
    edges[1][0] = true;

    edges[0][5] = true;
    edges[5][0] = true;

    edges[1][3] = true;
    edges[3][1] = true;

    edges[3][4] = true;
    edges[4][3] = true;

    edges[3][6] = true;
    edges[6][3] = true;

    edges[5][6] = true;
    edges[6][5] = true;

    edges[2][7] = true;
    edges[7][2] = true;


    bool canGo = CalulatePath_BFS(0, 6);

    printf("CanGo : %d", canGo);
}