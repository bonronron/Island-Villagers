// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_ObjectPriorityTest.generated.h"

/**
 * 
 */
UCLASS()
class DESERTOASISTEST_API UEnvQueryTest_ObjectPriorityTest : public UEnvQueryTest
{
	GENERATED_BODY()
	
	UEnvQueryTest_ObjectPriorityTest();
	virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;
};
