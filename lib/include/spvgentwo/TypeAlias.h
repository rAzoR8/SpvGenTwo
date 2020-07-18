#pragma once

#include "Type.h"

namespace spvgentwo
{
	namespace glsl
	{
		using vec2 = vector_t<float, 2>;
		using vec3 = vector_t<float, 3>;
		using vec4 = vector_t<float, 4>;

		using dvec2 = vector_t<double, 2>;
		using dvec3 = vector_t<double, 3>;
		using dvec4 = vector_t<double, 4>;

		using ivec2 = vector_t<int, 2>;
		using ivec3 = vector_t<int, 3>;
		using ivec4 = vector_t<int, 4>;

		using uvec2 = vector_t<unsigned int, 2>;
		using uvec3 = vector_t<unsigned int, 3>;
		using uvec4 = vector_t<unsigned int, 4>;

		using bvec2 = vector_t<bool, 2>;
		using bvec3 = vector_t<bool, 3>;
		using bvec4 = vector_t<bool, 4>;

		using mat2 = matrix_t<float, 2, 2>;
		using mat3 = matrix_t<float, 3, 3>;
		using mat4 = matrix_t<float, 4, 4>;
	} // !glsl

	namespace hlsl
	{	
		using float2 = vector_t<float, 2>;
		using float3 = vector_t<float, 3>;
		using float4 = vector_t<float, 4>;

		using double2 = vector_t<double, 2>;
		using double3 = vector_t<double, 3>;
		using double4 = vector_t<double, 4>;

		using int2 = vector_t<int, 2>;
		using int3 = vector_t<int, 3>;
		using int4 = vector_t<int, 4>;

		using uint2 = vector_t<unsigned int, 2>;
		using uint3 = vector_t<unsigned int, 3>;
		using uint4 = vector_t<unsigned int, 4>;

		using float2x2 = matrix_t<float, 2, 2>;
		using float3x3 = matrix_t<float, 3, 3>;
		using float4x4 = matrix_t<float, 4, 4>;
	} // !hlsl
} // !spvgentwo