/*
 * Reverse Words in a Sentence using a Linked-Based Stack
 *
 * For Discussion:
 * 1. How does pushing characters into a stack and then popping them naturally help in reversing a word?
 *    - A stack is a LIFO (Last-In-First-Out) data structure. When you read a word left-to-right
 *      and push its characters onto the stack, the last letter of the word is placed on the top.
 *      When you pop them back out, the last character comes out first, naturally reversing the sequence.
 *
 * 2. What should be the "trigger" to start popping characters from the stack to the output?
 *    - Encountering a space (' ') character. When a space is read, it signifies the end of a word.
 *      At this point, we should pop everything currently in the stack to the output, then append the space.
 *
 * 3. Linked Stack vs. Array Stack: Why is a Linked-Based implementation more flexible?
 *    - If the word or sentence length is unpredictable or extremely long, an Array-Based Stack
 *      might hit its fixed capacity and throw an overflow error, or require expensive resizing.
 *      A Linked-Based Stack grows dynamically by allocating memory per node as needed,
 *      making it perfectly flexible regardless of the word size, restricted only by the system's total memory.
 *
 * 4. What challenges might appear if we forget to handle the last word of the sentence?
 *    - If there is no trailing space at the very end of the string, the "trigger" is never activated
 *      for the final word. The characters of the last word will remain stuck inside the stack.
 *      We must ensure we empty the stack after the loop terminates to handle this edge case.
 */

#include <iostream>
#include <string>

using namespace std;

// Node structure for the Linked-Based Stack
struct Node
{
    char data;
    Node *next;

    Node(char val) : data(val), next(nullptr) {}
};

// Simple Linked-Based Stack for characters
class LinkedStack
{
private:
    Node *topNode;

public:
    LinkedStack() : topNode(nullptr) {}

    ~LinkedStack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(char val)
    {
        Node *newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop()
    {
        if (!isEmpty())
        {
            Node *temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    char top() const
    {
        if (!isEmpty())
        {
            return topNode->data;
        }
        return '\0'; // Return null char if empty
    }

    bool isEmpty() const
    {
        return topNode == nullptr;
    }
};

// Function to reverse individual words in a sentence
string reverseWords(const string &sentence)
{
    LinkedStack stack;
    string result = "";

    for (int i = 0; i < sentence.length(); i++)
    {
        // If we hit a space, it's the trigger to pop the characters of the previous word
        if (sentence[i] == ' ')
        {
            // Pop all chars from stack to result
            while (!stack.isEmpty())
            {
                result += stack.top();
                stack.pop();
            }
            // Append the space to separate words
            result += " ";
        }
        else
        {
            // Push character of the current word onto the stack
            stack.push(sentence[i]);
        }
    }

    // EDGE CASE: Handle the last remaining word (if the loop ends without a trailing space)
    while (!stack.isEmpty())
    {
        result += stack.top();
        stack.pop();
    }

    return result;
}

int main()
{
    string input = "Data Structures";
    cout << "Input: " << input << endl;

    string reversed = reverseWords(input);
    cout << "Output: " << reversed << endl;
    // Expected Output: ataD serutcurtS

    string input2 = "Linked Based Stack implementation is flexible";
    cout << "\nInput: " << input2 << endl;
    cout << "Output: " << reverseWords(input2) << endl;

    return 0;
}
