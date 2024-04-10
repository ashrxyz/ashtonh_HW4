// Author: Ashton Herrick
// Program: HW4
// Date Created: April 6, 2024
// Date Last Modified: April 9, 2024
//
// Problem: Write a program deisgned to implement a system for managing social media accounts, specifically
// focusing on tracking followers, followed accounts, and additional functionalities for Twitter and Instagram
// accounts.
//
// Implemented a template class SocialMediaAccount to manage social media accounts, including features for adding followers, followed accounts, and displaying them.
// Derived classes Twitter and Instagram with additional functionalities for retweet and like counts respectively.
// Created a Profile struct in the main.cpp file to represent user profiles.
// Defined instances of Twitter and Instagram classes with both string and Profile handlers in main.cpp, and tested all functionalities for these instances.

#include <iostream>
#include "SocialMedia.h" // Including the designated header file

using namespace std;

// Defining a struct for Profile
struct Profile{
    int userId;
    string username;
};

int main(){
    // Creating instances of Twitter and Instagram
    Twitter<string> TS(true, "TwitterUser", 100, 100);
    Twitter<Profile> TP(true, {123, "TwitterProfile"}, 100, 100);
    Instagram<string> IS(true, "InstagramUser", 100, 100);
    Instagram<Profile> IP(true, {456, "InstagramProfile"}, 100, 100);

    // Testing Twitter<string> instance
    TS.addFollower("Follower1");
    TS.addFollower("Follower2");
    TS.addFollowed("Followed1");
    TS.addFollowed("Followed2");

    TS.displayFollowers();
    TS.displayFollowed();

    // Testing Instagram<string> instance
    IS.addFollower("Follower3");
    IS.addFollowed("Followed3");

    IS.displayFollowers();
    IS.displayFollowed();

    // Testing Twitter<Profile> instance
    TP.addFollower({789, "Follower4"});
    TP.addFollowed({101, "Follower4"});

    TP.displayFollowers();
    TP.displayFollowed();

    // Testing Instagram<Profile> instance
    IP.addFollower({234, "Follower5"});
    IP.addFollowed({567, "Followed5"});

    IP.displayFollowers();
    IP.displayFollowed();

    return 0;
}
