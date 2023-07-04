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

	// ¿ì¾ÆÇÑ ·£´ý
	static unsigned long int seed = 1;
	static int ss_rand(void)
	{
		seed = seed * 1103515245 + 12345;
		return (unsigned int)(seed / 65536) % 32768;
	}

	static void ss_srand(unsigned int _seed)
	{
		seed = _seed;
	}
	
	static int GetRandomNumber(int _Range, int _StartNumber)
	{
		ss_srand(seed);
		int randvalue = (ss_rand() % _Range) + _StartNumber;;

		return randvalue;
	}
}