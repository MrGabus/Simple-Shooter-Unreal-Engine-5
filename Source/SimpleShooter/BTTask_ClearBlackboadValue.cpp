// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearBlackboadValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ClearBlackboadValue::UBTTask_ClearBlackboadValue()
{
	NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UBTTask_ClearBlackboadValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);	
	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	return EBTNodeResult::Succeeded;
}
