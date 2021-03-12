#pragma once
#include<string>
#include<utility>

namespace penguin2D
{
	class app
	{
	public:
		app(const std::string name,const int width,const int height)
			: m_name(name), m_width(width), m_height(height)
		{}
		virtual ~app() {}

		app(const app& rhs) = delete;
		app(app&& rhs) noexcept { app::move(std::move(rhs)); }
		app& operator=(const app& rhs) = delete;
		app& operator=(app&& rhs) noexcept { app::move(std::move(rhs)); }

	public:
		std::string getAppName() const { return m_name; }
		std::pair<int, int> getAppDiamensions() const { return std::make_pair(m_width, m_height); }
		int getAppWidth()  const { return m_width;	};
		int getAppHeight() const { return m_height; };

	public:
		void execute();

	private:
		void move(app&& rhs);

	private:
		std::string m_name;
		int m_width;
		int m_height;
	};
}