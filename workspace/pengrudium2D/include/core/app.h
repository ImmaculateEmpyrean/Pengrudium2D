#pragma once
#include<string>
#include<utility>

#include "window.h"

int main(int, char**);

namespace penguin2D
{
	class app
	{
	public:
		app(const std::string name,const int width,const int height)
			: winPtr(std::make_unique<window>(name,width,height))
		{}
		virtual ~app() {}

		app(const app& rhs) = delete;
		app(app&& rhs) noexcept { app::move(std::move(rhs)); }
		app& operator=(const app& rhs) = delete;
		app& operator=(app&& rhs) noexcept { app::move(std::move(rhs)); }

	public:
		std::string getAppName() const { return winPtr->getWindowTitle(); }
		std::pair<int, int> getAppDiamensions() const { return winPtr->getWindowDiamensions(); }
		int getAppWidth()  const { return winPtr->getWindowWidth();	};
		int getAppHeight() const { return winPtr->getWindowHeight(); };

		bool quitApplication() const {return winPtr->destroyWindow(); }

	public:
		virtual void execute() {};

	private:
		void process();

	private:
		void move(app&& rhs);

	private:
		std::unique_ptr<window> winPtr = nullptr;

		friend int ::main(int, char**);
	};
}