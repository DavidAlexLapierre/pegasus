#pragma once

namespace Amethyst {
	struct IDisposable {
	public:
		/// <summary>
		/// Dipose the object and its memory allocations
		/// </summary>
		virtual void dispose() = 0;
	};
}