#pragma once

#include <vector>

#include "Transform.h"


/**
 * @brief 애니메이션화할 캐릭터의 골격에서 모든 관절의 변화를 추적하는 클래스입니다.
 */
class Pose
{
public:
	/**
	 * @brief 포즈 클래스의 디폴트 생성자입니다.
	 */
	Pose() = default;


	/**
	 * @brief 포즈 클래스의 생성자입니다.
	 * 
	 * @param numJoints 관절 변환 목록 크기입니다.
	 */
	Pose(uint32_t numJoints)
	{
		Resize(numJoints);
	}


	/**
	 * @brief 포즈 클래스의 복사 생성자입니다.
	 * 
	 * @param instance 복사할 인스턴스입니다.
	 */
	Pose(Pose&& instance) noexcept
		: joints_(instance.joints_)
		, parents_(instance.parents_) {}


	/**
	 * @brief 포즈 클래스의 복사 생성자입니다.
	 *
	 * @param instance 복사할 인스턴스입니다.
	 */
	Pose(const Pose& instance) noexcept
		: joints_(instance.joints_)
		, parents_(instance.parents_) {}


	/**
	 * @brief 포즈 클래스의 가상 소멸자입니다.
	 */
	virtual ~Pose() {}


	/**
	 * @brief 포즈 클래스의 대입 연산자입니다.
	 * 
	 * @param instance 대입 연산을 수행할 인스턴스입니다.
	 * 
	 * @return 대입 연산을 수행한 객체의 참조자를 반환합니다.
	 */
	Pose& operator=(Pose&& instance) noexcept
	{
		if (this == &instance) return *this;

		joints_ = instance.joints_;
		parents_ = instance.parents_;

		return *this;
	}


	/**
	 * @brief 포즈 클래스의 대입 연산자입니다.
	 *
	 * @param instance 대입 연산을 수행할 인스턴스입니다.
	 *
	 * @return 대입 연산을 수행한 객체의 참조자를 반환합니다.
	 */
	Pose& operator=(const Pose& instance) noexcept
	{
		if (this == &instance) return *this;

		joints_ = instance.joints_;
		parents_ = instance.parents_;

		return *this;
	}


	/**
	 * @brief 두 포즈가 서로 일치하는지 확인합니다.
	 *
	 * @param instance 일치하는지 확인할 인스턴스입니다.
	 *
	 * @return 두 포즈가 일치한다면 true, 그렇지 않으면 false입니다.
	 */
	bool operator==(Pose&& instance) noexcept;


	/**
	 * @brief 두 포즈가 서로 일치하는지 확인합니다.
	 * 
	 * @param instance 일치하는지 확인할 인스턴스입니다.
	 * 
	 * @return 두 포즈가 일치한다면 true, 그렇지 않으면 false입니다.
	 */
	bool operator==(const Pose& instance);


	/**
	 * @brief 두 포즈가 서로 일치하지 않는지 확인합니다.
	 *
	 * @param instance 일치하지 않는지 확인할 인스턴스입니다.
	 *
	 * @return 두 포즈가 일치하지 않는다면 true, 그렇지 않으면 false입니다.
	 */
	bool operator!=(Pose&& instance) noexcept;


	/**
	 * @brief 두 포즈가 서로 일치하지 않는지 확인합니다.
	 *
	 * @param instance 일치하지 않는지 확인할 인스턴스입니다.
	 *
	 * @return 두 포즈가 일치하지 않는다면 true, 그렇지 않으면 false입니다.
	 */
	bool operator!=(const Pose& instance);


	/**
	 * @brief 포즈 내의 목록의 크기를 변경합니다.
	 * 
	 * @param size 변경할 크기입니다.
	 */
	void Resize(uint32_t size);


	/**
	 * @brief 포즈 내의 관절 변환 목록 크기를 얻습니다.
	 * 
	 * @return 포즈 내의 관절 변환 목록 크기를 반환합니다.
	 */
	uint32_t Size() const { return static_cast<uint32_t>(joints_.size()); }


private:
	/**
	 * @brief 관절 변환 목록입니다.
	 */
	std::vector<Transform> joints_;


	/**
	 * @brief 관절의 부모 인덱스 목록입니다.
	 */
	std::vector<int32_t> parents_;
};