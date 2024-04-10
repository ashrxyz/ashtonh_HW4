#ifndef SOCIALMEDIA_H
#define SOCIALMEDIA_H

#include <iostream>
#include <string>

using namespace std;

// Defining a template class for SocialMediaAccount
template<typename T>
class SocialMediaAccount{
private:
    int maxFollowers; // Maxium number of followers
    int maxFollowed; // Maximum number of accounts followed
    T handler; // Account owner
    T* followers; // Array to store followers
    T* followed; // Array to store followed accounts
    int followerCount; // Current number of followers
    int followedCount; // Current number of followed accounts
    bool isPrivate; // Flag to indicate if the account is private

public:
    // Constructor to initalize SocialMediaAccount
    SocialMediaAccount(bool _isPrivate, T _handler, int _maxFollowers, int _maxFollowed)
        : maxFollowers(_maxFollowers), maxFollowed(_maxFollowed), handler(_handler), followerCount(0), followedCount(0), isPrivate(_isPrivate){
        followers = new T[maxFollowers]; // Allocate memory for followers array
        followed = new T[maxFollowed]; // Allocate memory for followed array
    }

    // Destructor to free memory
    ~SocialMediaAccount(){
        delete[] followers; // Deallocate memory for followrs array
        delete[] followed; // Deallocate memory for followed array
    }

    // Setter for account handler
    void setHandler(T _handler){
        handler = _handler;
    }

    // Getter for account handler
    T getHandler() {
        return handler;
    }

    // Setter for privacy flag
    void setIsPrivate(bool _isPrivate){
        isPrivate = _isPrivate;
    }

    // Getter for privacy flag
    bool getIsPrivate(){
        return isPrivate;
    }

    // Add a follower
    void addFollower(T user){
        if (followerCount < maxFollowers){
            followers[followerCount++] = user;
        }
    }

    // Add a followed account
    void addFollowed(T user){
        if (followedCount < maxFollowed){
            followed[followedCount++] = user;
        }
    }

    // Display followers (if not private)
    void displayFollowers(){
        if (isPrivate){
            cout<<"Account is private, can't display followers."<<endl;
        } else{
            cout<<"Followers: ";
            for(int i=0; i < followerCount; ++i){
                cout<<followers[i]<<" ";
            }
            cout<<endl;
        }
    }

    // Display followed accounts (if not private)
    void displayFollowed(){
        if(isPrivate){
            cout<<"Account is private, can't display followed accounts."<<endl;
        } else{
            cout<<"Followed Accounts: ";
            for(int i=0; i < followedCount; ++i){
                cout<<followed[i]<<" ";
            }
            cout<<endl;
        }
    }
};

// Defining a template class for Twitter which is derived from SocialMediaAccount
template<typename T>
class Twitter : public SocialMediaAccount<T>{
private:
    int retweetCount; // Total number of retweets

public:
    // Constructor to initialize Twitter account
    Twitter(bool _isPrivate, T _handler, int _maxFollowers, int _maxFollowed)
        : SocialMediaAccount<T>(_isPrivate, _handler, _maxFollowers, _maxFollowed), retweetCount(0){}
    
    // Getter for retweet count
    int getRetweetCount(){
        return retweetCount;
    }

    // Setter for retweet count
    void setRetweetCount(int count){
        retweetCount = count;
    }

    // Incrementing retweet count
    void RT(){
        retweetCount++;
    }
};

// Defining a template class for Instagram which is derived from SocialMediaAccount
template<typename T>
class Instagram : public SocialMediaAccount<T>{
private:
    int likeCount; // Total number of likes

public:
    // Constructor to initalize Instagram account
    Instagram(bool _isPrivate, T _handler, int _maxFollowers, int _maxFollowed)
        : SocialMediaAccount<T>(_isPrivate, _handler, _maxFollowers, _maxFollowed), likeCount(0){}
    
    // Getter for like count
    int getLikeCount(){
        return likeCount;
    }

    // Setter for like count
    void setLikeCount(int count){
        likeCount = count;
    }

    // Incrementing like count
    void Like(){
        likeCount++;
    }
};

#endif // SOCIALMEDIA_H
