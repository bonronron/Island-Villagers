// Fill out your copyright notice in the Description page of Project Settings.
#include "EnvironmentQuery/EnvQueryTest_ObjectPriorityTest.h"
#include "Interfaces/Interface_InteractableObject.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_ActorBase.h"

UEnvQueryTest_ObjectPriorityTest::UEnvQueryTest_ObjectPriorityTest(){
    ValidItemType = UEnvQueryItemType_ActorBase::StaticClass();

};

void UEnvQueryTest_ObjectPriorityTest::RunTest(FEnvQueryInstance &QueryInstance) const
{
    UObject* Owner = QueryInstance.Owner.Get();
    if(!Owner) return;

    FloatValueMin.BindData(Owner,QueryInstance.QueryID);
    float MinThresholdValue = FloatValueMin.GetValue();

    FloatValueMax.BindData(Owner,QueryInstance.QueryID);
    float MaxThresholdValue = FloatValueMax.GetValue();
 

    for(FEnvQueryInstance::ItemIterator It(this,QueryInstance);It;++It) {
        float PlayerScore = 0;
        if(AActor* actor = GetItemActor(QueryInstance,It.GetIndex())){
            PlayerScore = IInterface_InteractableObject::Execute_GetPlayerScore(actor);
        }
       
        It.SetScore(TestPurpose,FilterType, PlayerScore,MinThresholdValue,MaxThresholdValue );
    }
}
