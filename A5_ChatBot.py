import nltk
from nltk.chat.util import Chat,reflections
reflections = {
  "i am"       : "you are",
  "i was"      : "you were",
  "i"          : "you",
  "i'm"        : "you are",
  "i'd"        : "you would",
  "i've"       : "you have",
  "i'll"       : "you will",
  "my"         : "your",
  "you are"    : "I am",
  "you were"   : "I was",
  "you've"     : "I have",
  "you'll"     : "I will",
  "your"       : "my",
  "yours"      : "mine",
  "you"        : "me",
  "me"         : "you"
}
pairs = [
    [
        r"my name is (.*)",
        ["Hello %1, How are you today ?",]
    ],
    [
        r"hi|hey|hello",
        ["Hello", "Hey there",]
    ],
    [
        r"what is your name ?",
        ["I am a bot created by Yash Rajput. you can call me Wed!",]
    ],
	[
        r"what is the timing of hospital ?",
        ["Monday to Saturday - Morning 10am to Evening 6pm",]
    ],
	[
        r"what is the name of hospital ?",
        ["OPERA HSPITAL",]
    ],
	[
        r"what is the timing of hospital ?",
        ["Morning 10am to Evening 6pm",]
    ],
    [
        r"how are you ?",
        ["I'm doing good.How about You ?",]
    ],
    [
        r"sorry (.*)",
        ["Its alright","Its OK, never mind",]
    ],
    [
        r"I am fine",
        ["Great to hear that, How can I help you?",]
    ],
    [
        r"i'm (.*) doing good",
        ["Nice to hear that","How can I help you?:)",]
    ],
    [
        r"(.*) age?",
        ["I'm a computer program and Seriously you are asking me this?",]
    ],
    [
        r"what (.*) want ?",
        ["To help everyone",]
    ],
    [
        r"(.*) created ?",
        ["Yash created me using Python's NLTK library ","top secret :)",]
    ],
    [
        r"(.*) (location|city) ?",
        ['Vigyan Nagar, Kota',]
    ],
    [
        r"average salary of doctor",
        ["It's 10 lakhs"]
    ],
    [
        r"what is appointment fees per person?",
        ["100 Rs per person."]
    ],
    [
        r"Can a doctor come for home check-up?",
        ["Yes, the the emergency type situation only."]
    ],
    [
        r"(.*)raining in (.*)",
        ["No rain since last week here in %2","Damn its raining too much here in %2"]
    ],
    [
        r"how (.*) health(.*)",
        ["I'm a computer program, so I'm always healthy ",]
    ],
    [
        r"Are there any check-up packages for today?",
        ["Today free diabetes checkup is ongoing.",]
    ],
    [
        r"I have been having ear pain for the past two weeks. Which doctor should I consult.",
        ["It is better you consult with ENT specialist. Today Dr. (Ja,es Sebastian | George kurien) is available."]
    ],
    [
        r"i am looking for online guides and courses to learn data science, can you suggest?",
        ["Crazy_Tech has many great articles with each step explanation along with code, you can explore"]
    ],
    [
        r"quit",
        ["Bye take care. See you soon :) ","It was nice talking to you. See you soon :)"]
    ],
	[
		r"Why don\'t you (.*)",
        [
            "Do you really think I don't %1?",
            "Perhaps eventually I will %1.",
            "Do you really want me to %1?",
		]
	]
]
def chat():
	print("Please ask me a Question?")
	chat=Chat(pairs,reflections)
	chat.converse()

if __name__=="__main__":
	chat()