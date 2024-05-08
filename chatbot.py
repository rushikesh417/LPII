import re 
import random

intent_keywords = {
    "greeting" : ["hi","hello"],
    "company_info" : ["information", "describe","service" ,"services", "about company", "about the company"],
    "booking" : ["register", "book", "booking"],
    "upcoming" : ["upcoming tours", "upcoming", "upcoming travels"],
    "packages" : ["tour packages", "travel packages", "tours", "travels"],
    "location" : ["location ", "located", "address", "situated"], 
    "payment" : ["payment options", "pay", "payment"], 
    "accomodation":["accomodation", "stay"],
    "cancellation" : ["refund policy", "cancel", "cancellation"], 
    "gratitude" : ["thanks", "thank you"]
    
}

intent_responses = {
    "greeting" : ["hello, you can ask me queries related to 'Adventure tours'", "Hi, how can I assist you?"],
    "company_info" : ["'Adventure tours and travels' is a company that offers variety of tours and travels  across the world. It is leading company in this domain since last 15 years."],
    "packages" :["We offer variety of packages which include tours across the world. Your can checkout detailed description of tours at adventure.com/tours"],
    "upcoming" : ["upcoming tours include tours to Australia, Bali and Greece."],
    "booking" : ["You can register for the tours by visiting our office or through our website."],
    "default" : ["Sorry I could not understand it."],
    "location":["Our office is located in Shivaji Nagar, Pune. You can checkout office locations on our website."],
    "payment" : ["We accept payment in various ways which includes cash payment, UPI and netbanking."],
    "accomodation":["We offer accomodation in premium hotels and ensure the comfort of our customers"],
    "cancellation" : ["The order has to be cancelled within 5 days after it is placed in order for amount to be refunded"], 
    "gratitude" : ["Its pleasure to help you."]

}

def get_regex_expression(keywords):
    regex_expression = r"\b(?:"
    for word in keywords : 
        regex_expression += word + "|"
    regex_expression = regex_expression[:-1] + r")\b"
    return regex_expression 

def check_keywords(query, regex_expression):
    found = re.search(regex_expression, query)
    return found 

def get_intent(query):
    intents = list(intent_keywords.keys())
    default_intent = "default"
    for intent in intents :
        keywords = intent_keywords[intent]
        regex_expression = get_regex_expression(keywords)
        if(check_keywords(query, regex_expression)):
            return intent
    return default_intent

def get_intent_based_response(intent):
    response = random.choice(intent_responses[intent])
    return response 

def get_response(query):
    query = query.lower()
    intent = get_intent(query)
    response = get_intent_based_response(intent)
    return response


print("Welcome to Adventure tours and travels. I am virtual help desk to answer your questions.")

while(True):
    query = input("query     : ")
    if(query=="exit"):
        print("Thank you")
        break
    response = get_response(query)
    print("response  : " + response)
    