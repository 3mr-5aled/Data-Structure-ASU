#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Influencer
{
public:
    int id;
    string name;
    int instagram_ID;

    Influencer(int id, string name, int instagram_ID) : id(id), name(name), instagram_ID(instagram_ID) {}
};

class MarketingAgency
{
    unordered_map<int, Influencer> influencers;
    unordered_map<int, unordered_set<int>> campaigns;

public:
    void add_influencer(int id, string name, string instagramID)
    {
        influencers[id] = Influencer(id, name, instagramID);
    }

    void create_campaign(int campaign_id, int number_of_influencers, int influencers_ids[])
    {
        for (int i = 0; i < number_of_influencers; i++)
        {
            campaigns[campaign_id].insert(influencers_ids[i]);
        }
    }

    void print_influencers_data()
    {
        for (auto influencer : influencers)
        {
            cout << "Name: " << influencer.second.name << endl;
            cout << "Instagram ID: " << influencer.second.instagramID << endl;
            cout << "------------------" << endl;
        }
    }

    void delete_influencer_from_campaign(int influencer_id, int campaign_id)
    {
        if (campaigns.find(campaign_id) != campaigns.end())
        {
            campaigns[campaign_id].erase(influencer_id);
        }
    }
};

int main()
{

    int campaign_id, number_of_influencer;

    cout << "Enter the campaign id: " << endl;
    cin >> campaign_id;
    cout << "Enter the number of influencers: " << endl;
    cin >> number_of_influencer;
    vector<Influencer> influencers;
    for (int i = 0; i < number_of_influencer; i++)
    {
        int influencer_id, instagram_id;
        string name;
        cout << "Enter the influencer id: " << endl;
        cin >> influencer_id;
        cout << "Enter the influencer name: " << endl;
        cin >> name;
        cout << "Enter the influencer instagram id: " << endl;
        cin >> instagram_id;
        Influencer influencer(influencer_id, name, instagram_id);
        influencers.push_back(influencer);
    }
    MarketingAgency agency;
    agency.add_influencer(influencers[0].id, influencers[0].name, influencers[0].instagram_ID);
    int influencer_ids[number_of_influencer];
    for (int i = 0; i < number_of_influencer; i++)
    {
        influencer_ids[i] = influencers[i].id;
    }
    agency.create_campaign(campaign_id, number_of_influencer, influencer_ids);
    agency.print_influencers_data();
    agency.delete_influencer_from_campaign(influencers[0].id, campaign_id);
    agency.print_influencers_data();

    return 0;
}