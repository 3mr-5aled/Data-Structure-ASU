#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

struct influencer
{
    int ID;
    string name;
    int instaId;
};

unordered_map<int, influencer> influencers;
unordered_map<int, unordered_set<int>> campaigns;

void create_campaign(int campaign_id, int number_of_influencer, int influencers_ids[])
{
    unordered_set<int> selectedInfluencers;
    for (int i = 0; i < number_of_influencer; i++)
    {
        selectedInfluencers.insert(influencers_ids[i]);
    }

    campaigns[campaign_id] = selectedInfluencers;
}

void print_influencers_data()
{
    for (const auto &entry : influencers)
    {
        cout << "Name: " << entry.second.name
             << ", Instagram ID: " << entry.second.instaId << '\n';
    }
}

void delete_influencer_from_campaign(int influencer_id, int campaign_id)
{
    auto campaignIt = campaigns.find(campaign_id);
    if (campaignIt == campaigns.end())
    {
        return;
    }

    campaignIt->second.erase(influencer_id);
}

int main()
{
    influencers[1] = {1, "Ahmed", 10101};
    influencers[2] = {2, "Mona", 20202};
    influencers[3] = {3, "Omar", 30303};

    int arr[] = {1, 2, 3};
    create_campaign(1, 2, arr);

    print_influencers_data();
    delete_influencer_from_campaign(2, 1);

    return 0;
}