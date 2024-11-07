#pragma once


struct Edge
{
	int From;	// 어디에서 
	int To;		// 어디로 연결한건지
	int Cost;	// 가는데 비용은 얼마인지
};


class Graph
{
public:
	void SetVertexs(vector<int> vertexs) { _vertexs = vertexs; }
	vector<int>& GetVertexs() { return _vertexs; }

	void SetEdges(vector<Edge> edges) { _edges = edges; }
	vector<Edge>& GetEdges() { return _edges; }

	static Graph MakeGraph(int type);

private:
	vector<int> _vertexs;
	vector<Edge> _edges;

};
