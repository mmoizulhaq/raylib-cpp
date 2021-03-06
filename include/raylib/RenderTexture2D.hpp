#ifndef RAYLIB_CPP_RENDERTEXTURE2D_HPP_
#define RAYLIB_CPP_RENDERTEXTURE2D_HPP_

#include "raylib.h"
#include "utils.hpp"

namespace raylib {
	class RenderTexture2D : public ::RenderTexture2D {
	public:
		RenderTexture2D(::RenderTexture2D renderTexture) {
			set(renderTexture);
		};
		RenderTexture2D(unsigned int Id) {
			id = Id;
		};
		RenderTexture2D(int width, int height) {
			set(LoadRenderTexture(width, height));
		}

		inline void set(::RenderTexture2D renderTexture) {
			id = renderTexture.id;
			texture = renderTexture.texture;
			depth = renderTexture.depth;
			depthTexture = renderTexture.depthTexture;
		}

		GETTERSETTER(float,Id,id)
		GETTERSETTER(Texture2D,Texture,texture)
		GETTERSETTER(Texture2D,Depth,depth)
		GETTERSETTER(bool,DepthTexture,depthTexture)

        RenderTexture2D& operator=(const ::RenderTexture2D& texture) {
            set(texture);
            return *this;
        }

        RenderTexture2D& operator=(const RenderTexture2D& texture) {
            set(texture);
            return *this;
        }

		~RenderTexture2D() {
			Unload();
		};

		void Unload() {
			UnloadRenderTexture(*this);
		}

		void BeginTextureMode() {
			::BeginTextureMode(*this);
		}
	};
	typedef RenderTexture2D RenderTexture;
}

#endif
