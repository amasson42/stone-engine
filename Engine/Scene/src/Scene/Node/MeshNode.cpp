// Copyright 2024 Stone-Engine

#include "Scene/Node/MeshNode.hpp"
#include "Scene/ISceneRenderer.hpp"
#include "Scene/RenderElement/Mesh.hpp"
#include "Scene/RenderElement/Material.hpp"

namespace Stone::Scene
{

    STONE_NODE_IMPLEMENTATION(MeshNode)

    MeshNode::MeshNode(const std::string &name)
        : PivotNode(name), _mesh(nullptr), _material(nullptr)
    {
    }

    MeshNode::MeshNode(const MeshNode &other)
        : PivotNode(other), _mesh(other._mesh), _material(other._material)
    {
    }

    MeshNode::~MeshNode()
    {
    }

    std::string MeshNode::debugDescription() const
    {
        std::string str = PivotNode::debugDescription();
        str.pop_back();
        str += ",mesh:" + (_mesh ? std::to_string(_mesh->getId()) : "null");
        str += ",material:" + (_material ? std::to_string(_material->getId()) : "null") + "}";
        return str;
    }

    std::shared_ptr<Mesh> MeshNode::getMesh() const
    {
        return _mesh;
    }

    void MeshNode::setMesh(std::shared_ptr<Mesh> mesh)
    {
        _mesh = mesh;
    }

    std::shared_ptr<Material> MeshNode::getMaterial() const
    {
        return _material;
    }

    void MeshNode::setMaterial(std::shared_ptr<Material> material)
    {
        _material = material;
    }

    const char *MeshNode::_termClassColor() const
    {
        return TERM_COLOR_BOLD TERM_COLOR_GREEN;
    }

    STONE_NODE_IMPLEMENTATION(InstancedMeshNode)

    InstancedMeshNode::InstancedMeshNode(const std::string &name)
        : MeshNode(name), _instancesTransforms()
    {
    }

    InstancedMeshNode::InstancedMeshNode(const InstancedMeshNode &other)
        : MeshNode(other), _instancesTransforms(other._instancesTransforms)
    {
    }

    InstancedMeshNode::~InstancedMeshNode()
    {
    }

    std::string InstancedMeshNode::debugDescription() const
    {
        std::string str = MeshNode::debugDescription();
        str.pop_back();
        str += ",instances:" + std::to_string(_instancesTransforms.size()) + "}";
        return str;
    }

    void InstancedMeshNode::addInstance(const Transform3D &transform)
    {
        _instancesTransforms.push_back(transform);
    }

    void InstancedMeshNode::removeInstance(size_t index)
    {
        assert(index < _instancesTransforms.size());
        _instancesTransforms.erase(_instancesTransforms.begin() + index);
    }

    void InstancedMeshNode::clearInstances()
    {
        _instancesTransforms.clear();
    }

    const std::vector<Transform3D> &InstancedMeshNode::getInstancesTransforms() const
    {
        return _instancesTransforms;
    }

} // namespace Stone::Scene
