#include "pch.h"
#include <iostream>
#include "Graph.h"
#include <stack>
#include <queue>
using namespace std;

int vertexSize = 8;
// 코딩 테스트 용
// 1. 정점 (인덱스가 곧 정점임.)
vector<bool> visited(vertexSize, false);
// 2. 간선 
//edges[1][3] => 1번에서 3번이 연결되어 있는가 ? edges[1] 안에 3이 포함되어 있는지
vector<vector<bool>> edges = vector<vector<bool>>(vertexSize, vector<bool>(vertexSize, 0));

//이 문제의 핵심
// 1. 도착판별
// 2. 갈 수 있는 노드를 어떻게 체크할 것인지.
// 3. 간선체크를 어떻게 할 것인지.

//DFS의 핵심
//  그래서 갈 수 있냐
//  절대로 가장 깔끔하게 가는 방법이 아님.

//시간복잡도 측면에서는
// O(n)
bool CalulatePath_DFS(int startNode, int endNode)
{
    //1. 내가 갈 수 있는 곳을 예약정점으로 만든다.
    stack<int> s;
    s.push(startNode);
    //2. 예약정점이 존재하는 한 반복한다.
    while (s.empty() == false)
    {
        //현재 위치가 current C++은 pop은 void 형식으로 빼주기만 함. 그래서 top을 해줘야함.
        int current = s.top();
        s.pop();
        if (current == endNode)
        {
            printf("연결되어있습니다\n");
            return true;
        }
        //해당 정점을 방문했다고 체크
        visited[current] = true;

        //내가 갈 수 있는 곳을 예약 정점으로 만든다.
        for (int i = 0; i < vertexSize; i++)
        {
            //연결되어 있는 간선 + 지나간 노드가 아닌 간선
            if (edges[current][i] == true && visited[i] == false)
            {
                s.push(i);
            }
        }
    }

    return false;
}
bool CalulatePath_BFS(int startNode, int endNode)
{
    //1. 내가 갈 수 있는 곳을 예약정점으로 만든다.
    queue<int> q;
    q.push(startNode);
    //2. 예약정점이 존재하는 한 반복한다.
    while (q.empty() == false)
    {
        //현재 위치가 current C++은 pop은 void 형식으로 빼주기만 함. 그래서 top을 해줘야함.
        int current = q.front();
        q.pop();
        if (current == endNode)
        {
            printf("연결되어있습니다\n");
            return true;
        }
        //해당 정점을 방문했다고 체크
        visited[current] = true;

        //내가 갈 수 있는 곳을 예약 정점으로 만든다.
        for (int i = 0; i < vertexSize; i++)
        {
            //연결되어 있는 간선 + 지나간 노드가 아닌 간선
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
    Graph g = Graph::MakeGraph(4);

    // 3. 그래프 완성 (graph4.png 기준)(인덱스 0 ~ 7 사용)
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
    bool canGo = CalulatePath_DFS(1, 3);

    printf("CanGo : %d", canGo);
}