#include <bits/stdc++.h>
using namespace std;

// Responses for various inquiries
unordered_map<string, string> responses = {
    {"greeting", "Hello! Welcome to our mobile repair shop. How can I assist you today?"},
    {"farewell", "Thank you for choosing our mobile repair services. Have a great day!"},
    {"help", "Sure, I'm here to help. What issues are you facing with your mobile?"},
    {"screen_cracked", "A cracked screen is a common issue. We can replace the screen for you. Please bring your mobile to our shop, and our technicians will take care of it."},
    {"battery_problem", "If you're experiencing battery issues, we can replace your mobile's battery. Bring it to our shop, and we'll ensure it gets fixed."},
    {"software_issue", "Software issues can often be resolved by resetting your mobile or updating its software. We can assist you with that. Please bring your phone to our shop, and our technicians will help you out."},
    {"water_damage", "Water damage can be critical for mobiles. We suggest immediately turning off your device and bringing it to our shop for professional repair. Do not attempt to power it on."},
    {"charging_issue", "If your mobile is not charging properly, it could be due to a faulty charging port or cable. We can diagnose and fix the issue at our shop."},
    {"network_problem", "If you're experiencing network or signal issues, it could be related to your mobile's antenna or network settings. Bring it to our shop, and we'll investigate the problem."},
    {"speaker_issue", "If you're having trouble with your mobile's speaker or microphone, it might be a hardware or software issue. Our technicians can diagnose and repair it for you."},
    {"button_not_working", "If the buttons on your mobile are not working, it could be due to physical damage or software issues. We'll inspect and fix the problem at our shop."},
    {"slow_performance", "If your mobile is running slow, it might be overloaded with apps or have software issues. We can optimize its performance and resolve any software issues."},
    {"default", "I apologize, but I couldn't understand your request. Please contact our customer support for assistance."}
};

class Rule{
    public:

    string pattern,response;

    Rule(string pattern ,string response){
        this->pattern=pattern;
        this->response=response;
    }
};

class chatbot{

    public:

    vector<Rule>rules;

    chatbot(vector<Rule>rules){
        this->rules=rules;
    }

    string get_ans(string input){

        transform(input.begin(),input.end() , input.begin() , ::tolower);

        for(auto it:rules){
            regex pattern(it.pattern);
            if(regex_search(input ,pattern)){
                return responses[it.response];
            }
            
        }

        return responses["default"];
    }
};


int main(){

    vector<Rule> rules = {
        Rule("\\b(?:hello|hi)\\b", "greeting"),
        Rule("\\b(?:goodbye|bye)\\b", "farewell"),
        Rule("\\b(?:help|support)\\b", "help"),
        Rule("\\b(?:screen|cracked)\\b", "screen_cracked"),
        Rule("\\b(?:battery|charge)\\b", "battery_problem"),
        Rule("\\b(?:software|update|reset)\\b", "software_issue"),
        Rule("\\b(?:water|damage)\\b", "water_damage"),
        Rule("\\b(?:charging|charge|power)\\b", "charging_issue"),
        Rule("\\b(?:network|signal)\\b", "network_problem"),
        Rule("\\b(?:speaker|microphone)\\b", "speaker_issue"),
        Rule("\\b(?:button|buttons)\\b", "button_not_working"),
        Rule("\\b(?:slow|performance|lag)\\b", "slow_performance")
    };

    chatbot obj(rules);

    cout<<"Welcomw to chat "<<endl;
    while(true){

        cout<<"user: ";
        string input;
        getline(cin ,input);

        if(input=="exit"){
            break;
        }

        string ans = obj.get_ans(input);
        cout<<"bot : "<<ans<<endl;

    }

    cout<<"Thanks for using the chatbot...."<<endl;
    return 0;
}