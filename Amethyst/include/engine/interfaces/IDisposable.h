#pragma once

namespace Amethyst {
	struct IDisposable {
	public:
		virtual void dispose() = 0;
	};
}