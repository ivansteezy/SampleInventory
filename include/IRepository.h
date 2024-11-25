#pragma once

namespace Repository {
	class IRepository {
	public:
		virtual bool readFromFile() = 0;
		virtual bool writeIntoFile() = 0;
	};
}