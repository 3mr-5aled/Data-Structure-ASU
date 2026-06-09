#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class Candidate
{
public:
    int id;
    string name;
    int votes;

    Candidate()
    {
        this->id = 0;
        this->name = "";
        this->votes = 0;
    }

    Candidate(int id, string name)
    {
        this->id = id;
        this->name = name;
        this->votes = 0;
    }
};

class VotingSystem
{
public:
    // id , candidate
    unordered_map<int, Candidate> candidates_map;
    // votes, candidate
    priority_queue<pair<int, int>> candidates;

    void vote_candidate(int id)
    {
        candidates_map[id].votes++;
        // candidates.push({candidates_map[id].votes, id});
        candidates.push(make_pair(candidates_map[id].votes, id));
    }
    void print_candidates_votes()
    {
        for (auto &candidate : candidates_map)
        {
            cout << candidate.second.name << " has " << candidate.second.votes << " votes." << endl;
        }
        // print candidates and their votes
    }
    void get_leading_candidate()
    {
        // print leading candidate
        cout << candidates_map[candidates.top().second].name << " with " << candidates.top().first << " votes." << endl;
    }
    void delete_candidate(int id)
    {
        // find candidate by id and delete from system
        candidates_map.erase(id);
    }
};

int main()
{
    Candidate candidate1(1, "Alice");
    Candidate candidate2(2, "Bob");
    Candidate candidate3(3, "Charlie");
    VotingSystem voting_system;
    voting_system.candidates_map[1] = candidate1;
    voting_system.candidates_map[2] = candidate2;
    voting_system.candidates_map[3] = candidate3;

    voting_system.vote_candidate(1);
    voting_system.vote_candidate(2);
    voting_system.vote_candidate(1);
    voting_system.vote_candidate(1);
    voting_system.vote_candidate(1);
    voting_system.vote_candidate(1);
    voting_system.vote_candidate(3);

    cout << "Candidates and their votes:" << endl;
    voting_system.print_candidates_votes();

    cout << "Leading candidate: ";
    voting_system.get_leading_candidate();

    voting_system.delete_candidate(2);
    cout << "Candidates and their votes:" << endl;
    voting_system.print_candidates_votes();

    return 0;
}