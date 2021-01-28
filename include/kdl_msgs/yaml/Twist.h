#pragma once
#include <yaml-cpp/yaml.h>
#include <kdl_msgs/Twist.h>

namespace YAML {

template <>
struct convert<KDL::Twist>
{
    static Node encode(const KDL::Twist &msg)
    {
        Node node;
        node["linear"] = msg.vel;
        node["angular"] = msg.rot;
        return node;
    }
    static bool decode(const Node &node, KDL::Twist &msg)
    {
        if (node.Type() == YAML::NodeType::Null) return true;
        if (node.Type() == YAML::NodeType::Map && node["linear"]) { 
            msg.vel = node["linear"].as<KDL::Vector>();
        } else {
            //leave field empty 
        }
        if (node.Type() == YAML::NodeType::Map && node["angular"]) {
            msg.rot = node["angular"].as<KDL::Vector>();
        } else {
            //leave field empty 
        }
        return true;
    }
};

} // namespace YAML
  