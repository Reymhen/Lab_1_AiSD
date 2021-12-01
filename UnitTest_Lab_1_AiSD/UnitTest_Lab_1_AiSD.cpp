#include "pch.h"
#include "CppUnitTest.h"
#include "../Algorithms_Lab_1.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab1
{
	TEST_CLASS(UnitTestLab1)
	{
	public:

		TEST_METHOD(EmptyConstructorTest)
		{
			List MyList;
			Assert::IsTrue(MyList.get_size() == 0);
		}
		TEST_METHOD(ConstructorWithDateTest)
		{
			List MyList(2);
			Assert::IsTrue(MyList.get_size() == 1);
			Assert::IsTrue(MyList.at(0) == 2);
		}
		TEST_METHOD(DescructorTest)
		{
			List MyList;
			MyList.push_back(5);
			MyList.push_front(8);
			MyList.push_front(1);
			Assert::IsTrue(MyList.get_size() == 3);
			MyList.~List();
			Assert::IsTrue(MyList.get_size() == 0);
		}
		TEST_METHOD(GetSizeTest)
		{
			List MyList;
			Assert::IsTrue(MyList.get_size() == 0);
			MyList.push_back(3);
			Assert::IsTrue(MyList.get_size() == 1);
			MyList.push_front(2);
			Assert::IsTrue(MyList.get_size() == 2);
			MyList.insert(9, 1);
			Assert::IsTrue(MyList.get_size() == 3);
			MyList.remove(1);
			Assert::IsTrue(MyList.get_size() == 2);
		}
		TEST_METHOD(IsEmptyTest)
		{
			List MyList;
			Assert::IsTrue(MyList.isEmpty() == 1);
			MyList.push_back(5);
			Assert::IsTrue(MyList.isEmpty() == 0);
		}

		TEST_METHOD(PushBackTest)
		{
			List MyList;
			Assert::IsTrue(MyList.isEmpty() == 1);
			MyList.push_back(2);
			Assert::IsTrue(MyList.at(0) == 2);
			Assert::IsTrue(MyList.get_size() == 1);
			Assert::IsTrue(MyList.isEmpty() == 0);
			MyList.push_back(3);
			Assert::IsTrue(MyList.get_size() == 2);
			Assert::IsTrue(MyList.at(1) == 3);
		}
		TEST_METHOD(PushFrontTest)
		{
			List MyList;
			Assert::IsTrue(MyList.isEmpty() == 1);
			MyList.push_front(2);
			Assert::IsTrue(MyList.at(0) == 2);
			Assert::IsTrue(MyList.get_size() == 1);
			Assert::IsTrue(MyList.isEmpty() == 0);
			MyList.push_front(1);
			Assert::IsTrue(MyList.get_size() == 2);
			Assert::IsTrue(MyList.at(0) == 1);
		}
		TEST_METHOD(PopFrontTest)
		{
			List MyList;
			Assert::IsTrue(MyList.isEmpty() == 1);
			try {
				MyList.pop_front();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty. First element cannot be deleted", error.what());
			}
			MyList.push_back(10);
			MyList.push_front(1);
			Assert::IsTrue(MyList.isEmpty() == 0);
			Assert::IsTrue(MyList.get_size() == 2);
			try {
				MyList.pop_front();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty. First element cannot be deleted", error.what());
			}
			Assert::IsTrue(MyList.at(0) == 10);
			Assert::IsTrue(MyList.get_size() == 1);
		}
		TEST_METHOD(PopBackTest)
		{
			List MyList;
			Assert::IsTrue(MyList.isEmpty() == 1);
			try {
				MyList.pop_back();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty. Last element cannot be deleted", error.what());
			}
			MyList.push_back(10);
			MyList.push_front(1);
			Assert::IsTrue(MyList.isEmpty() == 0);
			Assert::IsTrue(MyList.get_size() == 2);
			try {
				MyList.pop_back();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty. Last element cannot be deleted", error.what());
			}
			Assert::IsTrue(MyList.at(0) == 1);
			Assert::IsTrue(MyList.get_size() == 1);
		}
		TEST_METHOD(InsertTest)
		{
			List MyList;
			try {
				MyList.insert(5, 0);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is greater than the maximum index of the List", error.what());
			}
			MyList.push_back(2);
			MyList.push_front(1);
			Assert::IsTrue(MyList.at(1) == 2);
			Assert::IsTrue(MyList.get_size() == 2);
			try {
				MyList.insert(7, 10);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is greater than the maximum index of the List", error.what());
			}
			try {
				MyList.insert(7, 1);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is greater than the maximum index of the List", error.what());
			}
			Assert::IsTrue(MyList.at(1) == 7);
			Assert::IsTrue(MyList.at(MyList.get_size() - 1) == 2);
			Assert::IsTrue(MyList.get_size() == 3);
			try {
				MyList.insert(5, 0);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is greater than the maximum index of the List", error.what());
			}
			Assert::IsTrue(MyList.get_size() == 4);
			Assert::IsTrue(MyList.at(0) == 5);
		}
		TEST_METHOD(AtTest)
		{
			List MyList;
			MyList.push_back(2);
			try {
				MyList.at(5);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index\n", error.what());
			}
			MyList.push_back(3);
			try {
				MyList.at(1);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index\n", error.what());
			}
			Assert::IsTrue(MyList.at(0) == 2);
			Assert::IsTrue(MyList.at(1) == 3);
		}
		TEST_METHOD(RemoveTest)
		{
			List MyList;
			MyList.push_back(4);
			MyList.push_front(3);
			MyList.push_front(2);
			MyList.push_front(1);
			Assert::IsTrue(MyList.get_size() == 4);
			try {
				MyList.remove(5);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}
			Assert::IsTrue(MyList.get_size() == 4);
			try {
				MyList.remove(3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}
			Assert::IsTrue(MyList.at(MyList.get_size() - 1) == 3);
			Assert::IsTrue(MyList.at(0) == 1);
			Assert::IsTrue(MyList.get_size() == 3);
			try {
				MyList.remove(0);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}
			Assert::IsTrue(MyList.get_size() == 2);
			MyList.push_back(4);
			Assert::IsTrue(MyList.get_size() == 3);
			try {
				MyList.remove(1);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}
			Assert::IsTrue(MyList.get_size() == 2);
			Assert::IsTrue(MyList.at(0) == 2);
		}
		TEST_METHOD(ClearTest)
		{
			List MyList;
			MyList.push_back(2);
			MyList.push_front(1);

			Assert::IsTrue(MyList.get_size() == 2);
			MyList.clear();
			Assert::IsTrue(MyList.get_size() == 0);
		}
		TEST_METHOD(SetTest)
		{
			List MyList;
			MyList.push_back(32);
			MyList.push_front(11);
			MyList.push_back(22);
			try {
				MyList.set(0, 1);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}
			try {
				MyList.set(1, 2);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}
			try {
				MyList.set(2, 3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}
			try {
				MyList.set(100, 55);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}

			Assert::IsTrue(MyList.at(0) == 1);
			Assert::IsTrue(MyList.at(1) == 2);
			Assert::IsTrue(MyList.at(MyList.get_size() - 1) == 3);
		}

		TEST_METHOD(FindLastTest)
		{
			List MyList;
			MyList.push_back(3);
			MyList.push_front(1);

			List List_two;
			List_two.push_back(3);
			List_two.push_front(9);

			stringstream output;

			try {
				MyList.find_last(List_two);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Lists are not included in each other", error.what());
			}

			MyList.insert(9, 1);
			MyList.push_back(9);
			MyList.push_back(3);


			output << MyList.find_last(List_two);
			Assert::IsTrue(output.str() == "3");
			MyList.pop_back();

			output.str(std::string());
			stringstream output2;
			output << MyList.find_last(List_two);
			Assert::IsTrue(output.str() == "1");
		}
	};

}
