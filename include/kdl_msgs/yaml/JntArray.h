#pragma once
#include <yaml-cpp/yaml.h>
#include <kdl_msgs/JntArray.h>

namespace YAML {

  template <>
  struct convert<KDL::JntArray>
  {
    static Node encode(const KDL::JntArray& rhs)
    {
        Node node;
        if(rhs.rows() == 0)
        {
            node["data"] = std::vector<double>();
            return node;
        }
        for(int i=0;i<rhs.rows();++i)
            node["data"].push_back(rhs(i));
        return node;
    }
    static bool decode(const Node& node, KDL::JntArray& rhs)
    {
        if (node.Type() == YAML::NodeType::Null) return true;
        if(node["data"].Type() == YAML::NodeType::Sequence)
        {
            rhs.resize(node["data"].size());
            for(int i=0;i<node["data"].size();++i)
                rhs(i) = node["data"][i].as<double>();
        } else {
            //leave field empty 
        }
        return true;
    }
  };

} // namespace YAML
