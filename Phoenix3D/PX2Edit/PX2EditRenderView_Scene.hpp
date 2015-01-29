// PX2EditRenderView.hpp

#ifndef PX2EDITRENDERVIEW_SCENE_HPP
#define PX2EDITRENDERVIEW_SCENE_HPP

#include "PX2EditMapPre.hpp"
#include "PX2EditRenderView.hpp"

namespace PX2
{

	class EditRenderView_Scene : public EditRenderView
	{
	public:
		EditRenderView_Scene();
		virtual ~EditRenderView_Scene();

	protected:
		void _CreateGridGeometry();

		PX2::RenderablePtr mGrid;
		PX2::NodePtr mGridNode;

	public:
		enum ViewType
		{
			VT_TOP,
			VT_FRONT,
			VT_LEFT,
			VT_PERSPECTIVE,
			VT_MAX_TYPE
		};
		void SetViewType(ViewType viewType);
		ViewType GetViewType();

		enum ViewDetail
		{
			VD_WIREFRAME,
			VD_SOLID,
			VD_TEXTURED
		};
		void SetViewDetail(ViewDetail viewDetail);
		ViewDetail GetViewDetail() const;

		RenderStep *GetRenderStep();

	protected:
		void _ClickSelect(const APoint &scrPos);
		void _ClickSelectScene(const APoint &scrPos, SelectMode mode);

		ViewType mViewType;
		ViewDetail mViewDetail;
		APoint mSelectPoint;

	public:
		void OnMoveHV(bool isAltDown, float h, float v);

		virtual void OnSize(const Sizef& size);
		virtual void OnLeftDown(const APoint &pos);
		virtual void OnLeftUp(const APoint &pos);
		virtual void OnMiddleDown(const APoint &pos);
		virtual void OnMiddleUp(const APoint &pos);
		virtual void OnMouseWheel(float delta);
		virtual void OnRightDown(const APoint &pos);
		virtual void OnRightUp(const APoint &pos);
		virtual void OnMotion(const APoint &pos);

	protected:
		void _MoveCamera(float horz, float vert); //< ͸�ӽǶȣ��������߷����ƶ�
		void _PanCamera(const float &horz, const float &vert); //< ͸�ӽǶȣ����������ƶ��������ӽǺ�MoveCameraһ��
		void _ZoomCamera(float zoom);
		void _RolateCamera(float horz, float vert);
		void _RoundCamera(float horz, float vert);

	protected:
		void _CreateNodeCtrl();

		SceneNodeCtrlPtr mSceneNodeCtrl;
		BoundCtrlPtr mBoundCtrl;
		PX2::NodePtr mSceneCtrlNode;
	};

	typedef Pointer0<EditRenderView_Scene> EditRenderView_ScenePtr;

}

#endif