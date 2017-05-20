#include <boost/graph/adjacency_list.hpp>
#include <utility>
#include <vector>
#include <iostream>
#include <cmath>
#include "bridge.h"


std::vector<std::pair<vertex_descriptor, vertex_descriptor>> bridge_find(graph_t graph)
{
  size_t time = 0;
  std::vector<dfs_node> dfstree(boost::num_vertices(graph));
  vertex_iterator v, v_end;
  std::vector<std::pair<vertex_descriptor, vertex_descriptor>> res;
  for (boost::tie(v, v_end) = vertices(graph); v != v_end; ++v)
  {
    if (!dfstree[*v].id)
    {
      dfs_support(*v, graph, dfstree, time, res, *v);
    }
  }
  return res;
}

void dfs_support(vertex_descriptor v, graph_t  &graph
                 , std::vector<dfs_node> &dfsgraph, size_t &time
                 , std::vector<std::pair<vertex_descriptor, vertex_descriptor>> &res
                 , vertex_descriptor pred) {
    dfsgraph[v].id = true;
    dfsgraph[v].ret = dfsgraph[v].enter = time++;

    adjacency_iterator u, u_end;
    for (boost::tie(u, u_end) = adjacent_vertices(v, graph); u != u_end; ++u) {
      if (pred != *u) {
        if (dfsgraph[*u].id)
          dfsgraph[v].ret = std::min(dfsgraph[v].ret, dfsgraph[*u].enter);
        else {
          dfs_support(*u, graph, dfsgraph, time, res, v);
          dfsgraph[v].ret = std::min(dfsgraph[v].ret, dfsgraph[*u].ret);
          if (dfsgraph[*u].ret > dfsgraph[v].enter)
              res.push_back(std::make_pair(v, *u));
        }
      }
    }
}
