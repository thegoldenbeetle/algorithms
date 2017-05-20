#ifndef BRIDGE_H
#define BRIDGE_H
#include <vector>
#include <utility>
#include <boost/graph/adjacency_list.hpp>

typedef boost::property<boost::edge_weight_t, int> EdgeWeightProperty;
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS, boost::no_property, EdgeWeightProperty > graph_t;
typedef boost::graph_traits<graph_t>::vertex_iterator vertex_iterator;
typedef boost::graph_traits<graph_t>::adjacency_iterator adjacency_iterator;
typedef boost::graph_traits<graph_t>::vertex_descriptor vertex_descriptor;

struct dfs_node {
  size_t ret = 0, enter = 0;
  bool id = false;
};

std::vector<std::pair<vertex_descriptor, vertex_descriptor>> bridge_find(graph_t graph);

void dfs_support(vertex_descriptor v, graph_t  &graph
                 , std::vector<dfs_node> &dfsgraph, size_t &time
                 , std::vector<std::pair<vertex_descriptor, vertex_descriptor> > &res, vertex_descriptor pred);

#endif // BRIDGE_H
