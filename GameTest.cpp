#include "pch.h"
#include "CppUnitTest.h"
#include "../2048/GamePole.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameTest
{
	TEST_CLASS(GameTest)
	{
	public:
		
		TEST_METHOD(checkPositionTest1)
		{
			GamePole* pole = new GamePole(4);
			Assert::AreEqual(true, pole->checkPosition(1, 1));
		}

		TEST_METHOD(checkPositionTest2)
		{
			GamePole* pole = new GamePole(4);
			Assert::AreEqual(true, pole->checkPosition(3, 3));
		}

		TEST_METHOD(checkPositionTest3)
		{
			GamePole* pole = new GamePole(4);
			Assert::AreEqual(false, pole->checkPosition(5, 7));
		}

		TEST_METHOD(checkPoleSizeTest1)
		{
			GamePole* pole = new GamePole(4);
			Assert::AreEqual(4, pole->getPoleSize());
		}

		TEST_METHOD(checkPoleSizeTest2)
		{
			GamePole* pole = new GamePole(5);
			Assert::AreEqual(5, pole->getPoleSize());
		}

		TEST_METHOD(newTileTest1)
		{
			GamePole* pole = new GamePole(5);
			int tile = pole->genNewTile();
			Assert::AreEqual(true, tile == 2 || tile == 4);
		}

		TEST_METHOD(checkChoosetest)
		{
			GamePole* pole = new GamePole(2);
			Assert::AreEqual(310, pole->checkChoose(2));
		}
	};
}
