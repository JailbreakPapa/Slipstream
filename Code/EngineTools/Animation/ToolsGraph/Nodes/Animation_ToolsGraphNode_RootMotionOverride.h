#pragma once
#include "Animation_ToolsGraphNode.h"

//-------------------------------------------------------------------------

namespace EE::Animation::GraphNodes
{
    class RootMotionOverrideToolsNode final : public FlowToolsNode
    {
        EE_REFLECT_TYPE( RootMotionOverrideToolsNode );

    public:

        RootMotionOverrideToolsNode();

        virtual GraphValueType GetValueType() const override { return GraphValueType::Pose; }
        virtual char const* GetTypeName() const override { return "Root Motion Override"; }
        virtual char const* GetCategory() const override { return "Animation/Root Motion"; }
        virtual TBitFlags<GraphType> GetAllowedParentGraphTypes() const override { return TBitFlags<GraphType>( GraphType::BlendTree ); }
        virtual int16_t Compile( GraphCompilationContext& context ) const override;

    private:

        // Set to negative to disable the velocity limiter
        EE_REFLECT() float                m_maxLinearVelocity = -1.0f;

        // Set to negative to disable the velocity limiter
        EE_REFLECT() float                m_maxAngularVelocity = -1.0f;

        // Limits
        EE_REFLECT() bool                 m_overrideHeadingX = true;
        EE_REFLECT() bool                 m_overrideHeadingY = true;
        EE_REFLECT() bool                 m_overrideHeadingZ = true;
        EE_REFLECT() bool                 m_allowPitchForFacing = false;

        // Events
        EE_REFLECT() bool                 m_listenForRootMotionEvents = false;
    };
}