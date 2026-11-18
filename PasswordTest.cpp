/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, long_repeating_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaaaaaaaaaooaoaoaoao");
	ASSERT_EQ(10, actual);
}

TEST(PasswordTest, no_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest2, single_letter_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Z");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest2, no_leading_characters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest2, all_lowercase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("qwertyuiop");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest2, all_uppercase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("QWERTYUIOP");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest2, mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("QwErTyUiOp");
	ASSERT_TRUE(actual);
}