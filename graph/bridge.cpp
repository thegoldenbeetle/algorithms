#include <boost/graph/adjacency_list.hpp>
#include <utility>
#include <vector>
#include <iostream>
#include <cmath>
#include "bridge.h"


std::vector<std::pair<vertex_descriptor, vertex_descriptor>> bridge_find(graph_t tree) {
  size_t time = 0;
  std::vector<dfs_node> dfstree(boost::num_vertices(tree));
  vertex_iterator v, v_end;
  std::vector<std::pair<vertex_descriptor, vertex_descriptor>> res;
  for (boost::tie(v, v_end) = vertices(tree); v != v_end; ++v) {
    if (!dfstree[*v].id) {
      dfs_support(*v, tree, dfstree, time, res);
    }
  }
  return res;
}

void dfs_support(vertex_descriptor v, graph_t  &tree
                 , std::vector<dfs_node> &dfstree, size_t &time
                 , std::vector<std::pair<vertex_descriptor, vertex_descriptor>> &res) {
    dfstree[v].id = true;
    dfstree[v].ret = dfstree[v].enter = time++;

    adjacency_iterator u, u_end;
    for (boost::tie(u, u_end) = adjacent_vertices(v, tree); u != u_end; ++u) {
      if (dfstree[*u].id)
        dfstree[v].ret = std::min(dfstree[v].ret, dfstree[*u].enter);
      else {
        boost::remove_edge(*u,v,tree);
        dfs_support(*u, tree, dfstree, time, res);
        dfstree[v].ret = std::min(dfstree[v].ret, dfstree[*u].ret);
        if (dfstree[*u].ret > dfstree[v].enter)
            res.push_back(std::make_pair(v, *u));
      }
    }
}
