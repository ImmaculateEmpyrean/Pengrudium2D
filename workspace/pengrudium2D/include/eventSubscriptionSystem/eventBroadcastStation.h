#pragma once
#include<memory>
#include<vector>
#include<string>

#include "events.h"

namespace penguin2D
{
	class EventBroadcastStation
	{
	public:
		void DispatchMessagesSuperior();
				
		void QueueBroadcast(std::unique_ptr<Event> BroadcastPackage); //This Message Is Used To Send in a package for Broadcast
		
		Ermine::SubscriptionTicket  QueueSubscription(std::unique_ptr<EventSubscription> Subscription);
		void						DestroySubscription(Ermine::SubscriptionTicket SubscriptionTicket); //Note We Have No Way To Check Ownership Of Subscription For Now Be VERY CAREFUL...................................................

		//This Message Will Be Instantly Dispatched From The Event Station Using The Calling Thread..
		void BlockingBroadcast(std::unique_ptr<Event> BroadcastPackage);

	private:
		//This Is The Storage Area We Will Store Everything Of Note Here...

		//All Different Events Are Stored In Different Containers So As To Parallilize Submitions.. Two Objects Wanting To Queue Two Different Types Of Events Need not wait ..   
		std::vector<ConcreteEvent> ConcreteEventsQueue; //These Are submitted events..
		std::recursive_mutex ConcreteEventsBufferMutex; 

		std::vector<KeyCallbackEvent> KeyCallbackEventsQueue;
		std::recursive_mutex KeyCallBackEventsBufferMutex;

		std::vector<CharacterCallbackEvent>CharacterCallbackEventsQueue;
		std::recursive_mutex CharacterCallBackEventsBufferMutex;

		std::vector<CursorPositionCallbackEvent>CursorPositionCallbackEventsQueue;
		std::recursive_mutex CursorPositionCallbackEventsBufferMutex;

		std::vector<MouseButtonCallbackEvent>MouseButtonCallbackEventsQueue;
		std::recursive_mutex MouseButtonCallbackEventsBufferMutex;

		std::vector<ScrollCallbackEvent>ScrollCallbackEventsQueue;
		std::recursive_mutex ScrollCallbackEventsBufferMutex;

		std::vector<TileSelectedEvent> TileSelectedCallbackEventsQueue;
		std::recursive_mutex TileSelectedCallbackEventsBufferMutex;

		std::vector<OnRenderTickEvent> OnRenderTickCallbackEventsQueue;
		std::recursive_mutex OnRenderTickCallbackEventsBufferMutex;

		std::vector<OnUpdateTickEvent> OnUpdateTickCallbackEventsQueue;
		std::recursive_mutex OnUpdateTickCallbackEventsBufferMutex;

		std::vector<OnBeginEvent> OnBeginEventsQueue;
		std::recursive_mutex OnBeginEventsBufferMutex;
		//Donot Forget to add destructors for these containers inside the destructor..

	private:
		//Start Store Subscriptions..//
		std::unordered_map<int,ConcreteEventSubscription> ConcreteEventSubscriptions;
		std::recursive_mutex ConcreteEventsSubscriptionsMutex;

		std::unordered_map<int,KeyCallbackEventSubscription> KeyCallbackEventsSubscriptions;
		std::recursive_mutex KeyCallbackEventsSubscriptionsMutex;

		std::unordered_map<int,CharacterCallbackEventSubscription> CharacterCallbackEventSubscriptions;
		std::recursive_mutex CharacterCallbackEventsSubscriptionsMutex;

		std::unordered_map<int,CursorPositionCallbackEventSubscription> CursorPositionCallbackEventSubscriptions;
		std::recursive_mutex CursorPositionCallbackEventsSubscriptionsMutex;

		std::unordered_map<int,MouseButtonCallbackEventSubscription> MouseButtonCallbackEventSubscriptions;
		std::recursive_mutex MouseButtonCallbackEventsSubscriptionsMutex;

		std::unordered_map<int,ScrollCallbackEventSubscription> ScrollCallbackEventSubscriptions;
		std::recursive_mutex ScrollCallbackEventsSubscriptionsMutex;

		std::unordered_map<int,TileSelectedEventSubscription> TileSelectedCallbackEventSubscriptions;
		std::recursive_mutex TileSelectedCallbackEventsSubscriptionsMutex;

		std::unordered_map<int,OnRenderTickEventSubscription> OnRenderTickCallbackEventSubscriptions;
		std::recursive_mutex OnRenderTickCallbackEventSubscriptionsMutex;

		std::unordered_map<int, OnUpdateTickEventSubscription> OnUpdateTickCallbackEventSubscriptions;
		std::recursive_mutex OnUpdateTickCallbackEventSubscriptionsMutex;

		std::unordered_map<int, OnBeginEventSubscription> OnBeginEventSubscriptions;
		std::recursive_mutex OnBeginEventSubscriptionsMutex;
		//Ended Store Subscription..//

	private:
#pragma region TemplateFunctions
		template<typename SubscriptionDataTypeName>
		void QueueSubscriptionTemplate(std::recursive_mutex& Mut,std::unordered_map<int, SubscriptionDataTypeName>& SubsQ, Ermine::EventSubscription* EvePtr,SubscriptionTicket& Ticket)
		{
			std::unique_lock<std::recursive_mutex> Lock(Mut);
			SubsQ.emplace(Ticket, *((SubscriptionDataTypeName*)(EvePtr)));
		}

		template<typename SubscriptionsQueue>
		void DestorySubscriptionTemplate(std::recursive_mutex& Mut, SubscriptionsQueue& SubQ, Ermine::SubscriptionTicket SubscriptionTicket)
		{
			std::unique_lock<std::recursive_mutex> Lock(Mut);
			//if(SubQ.erase(SubscriptionTicket) == 0)
			auto iter = SubQ.find(SubscriptionTicket);

			if (iter != SubQ.end())
			{
				iter->second.SetSubscriptionTermination();
			}
			else
			{
				STDOUTDefaultLog_Warn("Invalid Ticket Submitted For Erasing.. Could Not Erase A Subscription");
			}	
			CloseSubscriptionTicket(SubscriptionTicket);
		}

		template<typename EventsQueue,typename SubscriberQueue>
		void DispatchMessages(std::recursive_mutex& EventQueueMutex,EventsQueue& EQ,SubscriberQueue& SQ,std::recursive_mutex& SubscriberQueueMutex)
		{
			std::unique_lock EventQueueLock = std::unique_lock(EventQueueMutex);
			std::unique_lock SubscriberQueueLock = std::unique_lock(SubscriberQueueMutex);

			for (int i = 0; i < EQ.size(); i++)
			{
				for (auto j = SQ.begin(); j != SQ.end(); j++) //for (auto& j : ConcreteEventSubscriptions)
				{
					//Start Delete Objects Which Are Marked For Deletion Right..//
					std::shared_ptr<Ermine::GeneratedObject> Subs = j->second.GetSubscribedObject();
					if (Subs != nullptr)
					{
						while (Subs->IsHandleValid() == false)
						{
							j = SQ.erase(j);
							if (j == SQ.end())
								break;

							Subs = j->second.GetSubscribedObject();
						}
						if (j == SQ.end())
							break;

						auto Health = Subs->GetObjectHealth();
						while (Health == Ermine::ObjectStatus::StatusMarkedForDeletion)
						{
							j = SQ.erase(j);
							if (j == SQ.end())
								break;

							Subs = j->second.GetSubscribedObject();
							Health = Subs->GetObjectHealth();
						}
						if (j == SQ.end())
							break;

						while (j->second.GetSubscriptionHealth() == Ermine::SubscriptionHealth::WantToTerminate)
						{
							j = SQ.erase(j);
							if (j == SQ.end())
								break;
						}
						if (j == SQ.end())
							break;
						
						//Ended Delete Objects Which Are Marked For Deletion Right..//
						if (j->second.CanIRecieveEventFlag == true)
						{
							j->second.CallableObject(&EQ[i]);
						}

						//If The Event Is Already handled No Point In Handling it Further Right..
						if (EQ[i].IsEventHandled() == true)
							break;
					}
				}
				EQ.erase(EQ.begin() + i);
			}
		}

		template<typename SubscriberQueue,typename Event_Type>
		void DispatchMessageBlocking(SubscriberQueue& SQ, std::recursive_mutex& SubscriberQueueMutex,std::unique_ptr<Ermine::Event> EventRecieved)
		{
			//std::unique_lock EventQueueLock = std::unique_lock(EventQueueMutex);
			std::unique_lock SubscriberQueueLock = std::unique_lock(SubscriberQueueMutex);

			Ermine::Event* Eve = EventRecieved.release();
			Event_Type* EventPointer = ((Event_Type*)(Eve));

			for (auto j = SQ.begin(); j != SQ.end(); j++) //for (auto& j : ConcreteEventSubscriptions)
			{
				//Start Delete Objects Which Are Marked For Deletion Right..//
				std::shared_ptr<Ermine::GeneratedObject> Subs = j->second.GetSubscribedObject();
				if (Subs != nullptr)
				{
					while (Subs->IsHandleValid() == false)
					{
						j = SQ.erase(j);
						if (j == SQ.end())
							break;

						Subs = j->second.GetSubscribedObject();
					}
					if (j == SQ.end())
						break;

					auto Health = Subs->GetObjectHealth();
					while (Health == Ermine::ObjectStatus::StatusMarkedForDeletion)
					{
						j = SQ.erase(j);
						if (j == SQ.end())
							break;

						Subs = j->second.GetSubscribedObject();
						Health = Subs->GetObjectHealth();
					}
					if (j == SQ.end())
						break;

					while (j->second.GetSubscriptionHealth() == Ermine::SubscriptionHealth::WantToTerminate)
					{
						j = SQ.erase(j);
						if (j == SQ.end())
							break;
					}
					if (j == SQ.end())
						break;
					//Ended Delete Objects Which Are Marked For Deletion Right..//

					if (j->second.CanIRecieveEventFlag == true)
					{
						//Call The Event On All The Subscribers..
						j->second.CallableObject(EventPointer);
					}

					//If The Event Is Already handled No Point In Handling it Further Right..
					if (EventPointer->IsEventHandled() == true)
						break;
				}
				//The Usuage For Event Is Done.. Better Delete It So That It Wont Cause Memory Leaks...
				delete EventPointer;
			}

		}
#pragma endregion

		//This Method Gets A Subscription Ticket If A Slot Is Available.. The Bool is also Set True Remember.. 
		int GetOpenSubscriptionTicket();
		void CloseSubscriptionTicket(int SubscriptionTicket);

		//void RendererUpdateDaemonThreadFunction();
	private:
		//This Container Hopefully Keeps The Subscription Tickets Given Out In Track..
		static std::vector<bool> SubscriptionTicketsInUse;

		std::thread RendererUpdateDaemon;
	};
}