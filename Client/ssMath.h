#pragma once


namespace ss::math
{
	struct Vector2
	{
		float x;
		float y;

		Vector2()
			: x(0.0f)
			, y(0.0f)
		{

		}

		Vector2 operator+(Vector2 _other)
		{
			Vector2 ret;
			ret.x = x + _other.x;
			ret.y = y + _other.y;
			return ret;
		}

		Vector2 operator-(Vector2 _other)
		{
			Vector2 ret;
			ret.x = x - _other.x;
			ret.y = y - _other.y;
			return ret;
		}

		Vector2 operator*(Vector2 _other)
		{
			Vector2 ret;
			ret.x = x * _other.x;
			ret.y = y * _other.y;
			return ret;
		}

		void operator+=(Vector2 other)
		{
			x += other.x;
			y += other.y;
		}
	};
}