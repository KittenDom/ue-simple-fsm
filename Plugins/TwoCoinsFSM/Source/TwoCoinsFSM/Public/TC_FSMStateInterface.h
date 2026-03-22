// Copyright @subajat1 2026.

#pragma once

#include "UObject/Interface.h"

#include "TC_FSMStateInterface.generated.h"

UINTERFACE(MinimalAPI)
class UTC_FSMStateInterface : public UInterface
{
	GENERATED_BODY()
};

class TWOCOINSFSM_API ITC_FSMStateInterface
{
	GENERATED_BODY()

public:
	virtual void Enter() = 0;
	virtual void Exit() = 0;
	virtual void Update(float deltaTime) = 0;
};