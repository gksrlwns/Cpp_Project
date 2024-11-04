#include "pch.h"
#include "Graph.h"
Graph Graph::MakeGraph(int type)
{
	Graph rv;

	if (type == 1)
	{
		for (int i = 0; i < 5; i++)
		{
			rv._vertexs.push_back(i);
		}

		//A-D
		{
			Edge edge;
			edge.From = 0;
			edge.To = 3;
			edge.Cost = 8;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 3;
			edge.To = 0;
			edge.Cost = 8;

			rv._edges.push_back(edge);
		}

		//B - C
		{
			Edge edge;
			edge.From = 1;
			edge.To = 2;
			edge.Cost = 2;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 2;
			edge.To = 1;
			edge.Cost = 2;

			rv._edges.push_back(edge);
		}

		//C - D
		{
			Edge edge;
			edge.From = 2;
			edge.To = 3;
			edge.Cost = 6;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 3;
			edge.To = 2;
			edge.Cost = 6;

			rv._edges.push_back(edge);
		}

		//D - E
		{
			Edge edge;
			edge.From = 3;
			edge.To = 4;
			edge.Cost = 3;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 4;
			edge.To = 3;
			edge.Cost = 3;

			rv._edges.push_back(edge);
		}

		//D - F
		{
			Edge edge;
			edge.From = 3;
			edge.To = 5;
			edge.Cost = 4;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 5;
			edge.To = 3;
			edge.Cost = 4;

			rv._edges.push_back(edge);
		}
	}
	else if (type == 2)
	{
		for (int i = 0; i < 8; i++)
		{
			rv._vertexs.push_back(i + 1);
		}

		//1 - 2
		{
			Edge edge;
			edge.From = 1;
			edge.To = 2;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 2;
			edge.To = 1;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}

		//1 - 5
		{
			Edge edge;
			edge.From = 1;
			edge.To = 5;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 5;
			edge.To = 1;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}

		//1 - 8
		{
			Edge edge;
			edge.From = 1;
			edge.To = 8;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 8;
			edge.To = 1;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}

		//4 - 6
		{
			Edge edge;
			edge.From = 4;
			edge.To = 6;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 6;
			edge.To = 4;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}


		//4 - 7
		{
			Edge edge;
			edge.From = 4;
			edge.To = 7;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 7;
			edge.To = 4;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}


		//6 - 7
		{
			Edge edge;
			edge.From = 6;
			edge.To = 7;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 7;
			edge.To = 6;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
	}
	else if (type == 3)
	{
		rv._vertexs.push_back(1);
		rv._vertexs.push_back(2);
		rv._vertexs.push_back(3);
		rv._vertexs.push_back(5);
		rv._vertexs.push_back(8);

		//1 - 2
		{
			Edge edge;
			edge.From = 1;
			edge.To = 2;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 2;
			edge.To = 1;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}

		//1 - 5
		{
			Edge edge;
			edge.From = 1;
			edge.To = 5;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 5;
			edge.To = 1;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}


		//1 - 8
		{
			Edge edge;
			edge.From = 1;
			edge.To = 8;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 8;
			edge.To = 1;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}


		//2 - 3
		{
			Edge edge;
			edge.From = 2;
			edge.To = 3;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 3;
			edge.To = 2;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}

		//3 - 5
		{
			Edge edge;
			edge.From = 3;
			edge.To = 5;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 5;
			edge.To = 3;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}

		//5 - 8
		{
			Edge edge;
			edge.From = 5;
			edge.To = 8;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 8;
			edge.To = 5;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
	}
	else if (type == 4)
	{
		for (int i = 1; i <= 8; i++)
		{
			rv._vertexs.push_back(i);
		}

		//1 - 2
		{
			Edge edge;
			edge.From = 1;
			edge.To = 2;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 2;
			edge.To = 1;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}

		//1 - 6
		{
			Edge edge;
			edge.From = 1;
			edge.To = 6;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 6;
			edge.To = 1;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}

		//4 - 5
		{
			Edge edge;
			edge.From = 4;
			edge.To = 5;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 5;
			edge.To = 4;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}

		//4 - 7
		{
			Edge edge;
			edge.From = 4;
			edge.To = 7;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 7;
			edge.To = 4;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}

		//6 - 7
		{
			Edge edge;
			edge.From = 6;
			edge.To = 7;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 7;
			edge.To = 6;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}

		//3 - 8
		{
			Edge edge;
			edge.From = 3;
			edge.To = 8;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
		{
			Edge edge;
			edge.From = 8;
			edge.To = 3;
			edge.Cost = 1;

			rv._edges.push_back(edge);
		}
	}

	return rv;
}