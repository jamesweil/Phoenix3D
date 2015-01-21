// PX2Selection.hpp

#ifndef PX2SELECTION_HPP
#define PX2SELECTION_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2Object.hpp"
#include "PX2APoint.hpp"
#include "PX2AVector.hpp"

namespace PX2
{

	class Selection : public Singleton<Selection>
	{
	public:
		Selection();
		virtual ~Selection();

		void AddObject(PX2::Object *obj);
		void RemoveObject(PX2::Object *obj);
		PX2::Object *GetObjectAt(int i);
		int GetNumObjects();
		bool IsObjectIn(PX2::Object *obj);
		void Clear();

		const PX2::APoint &GetCenter() const;
		float GetRadius() const;

	private:
		void _UpdateSelect();

		std::vector<PX2::ObjectPtr> mObjects;
		PX2::APoint mCenter;
		float mBoundRadius;
	};

#include "PX2Selection.inl"
#define PX2_SELECTION Selection::GetSingleton()

}

#endif