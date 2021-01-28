#pragma once
#include <yaml-cpp/yaml.h>
#include <kdl_msgs/Vector.h>

namespace YAML {

template <>
struct convert<KDL::Vector>
{
    static Node encode(const KDL::Vector &msg)
    {
        Node node;
        node["x"] = msg.x();
        node["y"] = msg.y();
        node["z"] = msg.z();
        return node;
    }
    static bool decode(const Node &node, KDL::Vector &msg)
    {
        if (node.Type() == YAML::NodeType::Null) return true;
        if (node.Type() == YAML::NodeType::Map && node["x"]) {
            msg.x( node["x"].as<double>() );
        } else {
            //leave field empty 
        }      
        if (node.Type() == YAML::NodeType::Map && node["y"]) {
            msg.y( node["y"].as<double>() );
        } else {
            //leave field empty 
        }        
        if (node.Type() == YAML::NodeType::Map && node["z"]) {
            msg.z( node["z"].as<double>() );
        } else {
            //leave field empty 
        }
        return true;
    }
};

} // namespace YAML
  