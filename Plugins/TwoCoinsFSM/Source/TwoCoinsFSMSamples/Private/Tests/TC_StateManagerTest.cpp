// TC_SimpleStateManagerTests.h
#pragma once

#include "CoreMinimal.h"
#include "Tests/AutomationCommon.h"
#include "TC_SimpleStateManager.h"
#include "TC_FSMSystem.h"

BEGIN_DEFINE_SPEC(TC_SimpleStateManagerSpec,
                  "TwoCoinsFSM.TC_SimpleStateManager",
                  EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::
                  ProductFilter)
	TWeakObjectPtr<UTC_SimpleStateManager> TestComponent;
	TWeakObjectPtr<UTC_FSMSystem> TestFSM;
END_DEFINE_SPEC(TC_SimpleStateManagerSpec)

void TC_SimpleStateManagerSpec::Define()
{
	Describe("TC_SimpleStateManager Initialization",
	         [this]()
	         {
		         It("Should initialize FSM successfully",
		            [this]()
		            {
			            // Setup
			            TestComponent = NewObject<UTC_SimpleStateManager>();
			            TestComponent->RegisterComponent();

			            // Test
			            bool bResult = TestComponent->ReinitializeFSM();

			            // Verify
			            TestComponent->UnregisterComponent();
			            TestComponent = nullptr;
			            TestTrue("FSM initialization should succeed", bResult);
		            });

		         It("Should handle BeginPlay correctly",
		            [this]()
		            {
			            // Setup
			            TestComponent = NewObject<UTC_SimpleStateManager>();
			            TestComponent->RegisterComponent();

			            // Test
			            TestComponent->BeginPlay();

			            // Verify
			            TestComponent->UnregisterComponent();
			            TestComponent = nullptr;
		            });
	         });

	Describe("TC_SimpleStateManager State Management",
	         [this]()
	         {
		         It("Should transition to valid states",
		            [this]()
		            {
			            // Setup
			            TestComponent = NewObject<UTC_SimpleStateManager>();
			            TestComponent->RegisterComponent();

			            // Initialize FSM
			            TestComponent->ReinitializeFSM();

			            // Test state transition
			            TestComponent->StateTransitionTo(TEXT("IDLE"));

			            // Verify
			            TestComponent->UnregisterComponent();
			            TestComponent = nullptr;
		            });

		         It("Should handle state transitions properly",
		            [this]()
		            {
			            // Setup
			            TestComponent = NewObject<UTC_SimpleStateManager>();
			            TestComponent->RegisterComponent();

			            // Initialize FSM
			            TestComponent->ReinitializeFSM();

			            // Test multiple transitions
			            TestComponent->StateTransitionTo(TEXT("IDLE"));
			            TestComponent->StateTransitionTo(TEXT("COIN1"));
			            TestComponent->StateTransitionTo(TEXT("COIN2"));

			            // Verify
			            TestComponent->UnregisterComponent();
			            TestComponent = nullptr;
		            });
	         });

	Describe("TC_SimpleStateManager Lifecycle",
	         [this]()
	         {
		         It("Should handle EndPlay correctly",
		            [this]()
		            {
			            // Setup
			            TestComponent = NewObject<UTC_SimpleStateManager>();
			            TestComponent->RegisterComponent();

			            // Initialize FSM
			            TestComponent->ReinitializeFSM();

			            // Test EndPlay
			            TestComponent->EndPlay(EEndPlayReason::RemovedFromWorld);

			            // Verify
			            TestComponent = nullptr;
		            });

		         It("Should cleanup resources properly",
		            [this]()
		            {
			            // Setup
			            TestComponent = NewObject<UTC_SimpleStateManager>();
			            TestComponent->RegisterComponent();

			            // Initialize FSM
			            TestComponent->ReinitializeFSM();

			            // Verify
			            TestComponent->UnregisterComponent();
			            TestComponent = nullptr;
		            });
	         });
}