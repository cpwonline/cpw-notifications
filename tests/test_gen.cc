/*
 * test_gen.cc
 * 
 * Copyright 2020 CPW Online <josefelixrc@outlook.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * For more information see the LICENCE file.
 * 
 */
 
 
#include <iostream>
#include "gtest/gtest.h"
#include "cpw_notifications.h"

class TestGen : public ::testing::Test
{
	protected:
		void SetUp() override;
		void TearDown() override;

		CPWNotifications *TestObj_;
};

//-----------------------------------------------------------------------------

void TestGen::SetUp()
{
    TestObj_ = new CPWNotifications();
}

void TestGen::TearDown()
{
    delete TestObj_;
}

//-----------------------------------------------------------------------------

TEST_F(TestGen, ViewVersionSoftware)
{
    ASSERT_EQ(0, cpw_notifications_VERSION_MAJOR);
    ASSERT_EQ(0, cpw_notifications_VERSION_MINOR);
    ASSERT_EQ(1, cpw_notifications_VERSION_PATCH);
}

TEST_F(TestGen, ViewFirstNotification)
{
	TestObj_->ReceiveData_((char*)"app.id.com", (char*)"nombre", (char*)"cuerpo", (char*)"battery-low");
	ASSERT_EQ(true, TestObj_->PrepareNotification_());
	TestObj_->AddThemedIcon_();
	TestObj_->ShowNotification_();
}

TEST_F(TestGen, ViewSecondNotification)
{
	TestObj_->ReceiveData_((char*)"app.id.com", (char*)"Otro nombre", (char*)"Otro cuerpo", (char*)"dialog-information");
	ASSERT_EQ(true, TestObj_->PrepareNotification_());
	TestObj_->AddThemedIcon_();
	TestObj_->ShowNotification_();
}

//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}