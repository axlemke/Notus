#pragma once

#include <basetsd.h>
#include <string>
#include "Libraries/Systems/RTTISystem/Source/Public/RTTICommon.h"

namespace HaveBlue
{
	class RTTI
	{
	public:
		virtual const UINT64& GetTypeId() const = 0;
	
		RTTI_USAGE virtual const RTTI* QueryInterface(UINT64 id) const;
		RTTI_USAGE virtual bool Is(UINT64 id) const;
		RTTI_USAGE virtual bool Is(const std::string& name) const;
		RTTI_USAGE virtual std::string GetTypeName() const;

		template <typename T>
		bool Is() const
		{
			return Is(T::TypeIdClass());
		}

		template <typename T>
		const T* As() const
		{
			if (Is<T>())
			{
				return static_cast<const T*>(this);
			}
			return nullptr;
		}

		template <typename T>
		T* As()
		{
			if (Is<T>())
			{
				return static_cast<T*>(this);
			}
			return nullptr;
		}
	};

	#define RTTI_DECLARATIONS(Type, ParentType, DLL_USAGE)                                                   \
		protected:                                                                                           \
			static DLL_USAGE UINT64 s_runTimeTypeId;														 \
																											 \
		public:                                                                                              \
																											 \
			typedef ParentType Parent;                                                                       \
			DLL_USAGE static std::string TypeName() { return std::string(#Type); }                           \
			DLL_USAGE virtual const UINT64& GetTypeId() const { return Type::TypeIdClass(); }				 \
			DLL_USAGE static const UINT64& TypeIdClass() { return s_runTimeTypeId; }						 \
			DLL_USAGE virtual const RTTI* QueryInterface(UINT64 id) const									 \
			{																								 \
				if (id == TypeIdClass())                                                                     \
					{ return static_cast<const RTTI*>(this); }                                               \
				else                                                                                         \
					{ return Parent::QueryInterface(id); }                                                   \
			}                                                                                                \
			DLL_USAGE virtual bool Is(UINT64 id) const												         \
			{                                                                                                \
				if (id == TypeIdClass())                                                                     \
					{ return true; }                                                                         \
				else                                                                                         \
					{ return Parent::Is(id); }                                                               \
			}                                                                                                \
			DLL_USAGE virtual bool Is(const std::string& name) const                                         \
			{                                                                                                \
				if (name == TypeName())                                                                      \
					{ return true; }                                                                         \
				else                                                                                         \
					{ return Parent::Is(name); }                                                             \
			}																								 \
			DLL_USAGE virtual std::string GetTypeName() const												 \
			{																								 \
				return std::string(#Type);																	 \
			}



	#define RTTI_DEFINITIONS_FULL(Type, Namespace) UINT64 Namespace::Type::s_runTimeTypeId = reinterpret_cast<UINT64>(&Namespace::Type::s_runTimeTypeId);
	#define RTTI_DEFINITIONS(Type) RTTI_DEFINITIONS_FULL(Type, HaveBlue)

	/*! \brief Abstract base class (interface) for objects that have tables and can clone themselves.

		\note We could instead define a class IUser to use multiple inheritance to derive from
				IClonable and RTTI, but single inheritance reduces the number of vtable pointers,
				therefore reduces memory usage.
	*/
	class IClonable : public RTTI
	{
		public:
			virtual ~IClonable() {}
			virtual IClonable* Clone() = 0;
	};
}