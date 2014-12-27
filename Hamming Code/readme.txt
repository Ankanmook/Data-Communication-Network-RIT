AUTHOR : Ankan Mookherjee
Id: axm3244

-------------------------------------------------------------------------------
DEVELOPMENT

The package contains 7 files apart from this file.
1)encode.cpp contains Encode function.
 
2)encode.h contains header files and signatures of methods in 
encode.cpp. This file links encode.h to encode.cpp.

3)flipper.cpp contains methods to flip a bit in stream of data.

4)flipper.h ontains header files and signatures of methods in 
flipper.cpp. This file links flipper.h to flipper.cpp.

3)decode.cpp contains Decoding Function to decode data
which was encrypted into encode and flipped in flipper.

4)decode.h ontains header files and signatures of methods in 
decode.cpp. This file links decode.h to decode.cpp.

5)Makefile for code execution

6)Input.txt for Putting Input text

7)Output.txt for Redirecting Output Text 

For this project I wrote three different programs. The first one, encode, encoded
an input in such a way that some types of errors can be corrected at the destination
(this is know as forward error correction). The third program, decode, will decode the
encoded information at the destination (correcting errors, if possible).
The first one will encode an input, the third one will decode the encoded data to
reconstruct the original input.
NOTE: I implemented a code for 8 data bits and 4 parity bits. i.e. each 8 bit data
grouping will be encoded in to 12 bits. Input function reads bytes and output
function writes bytes (for every two bytes that you read, you will output 3 bytes).

The second program, flipper, takes an input and randomly "flip" bits in that input.
The input (along with any "flipped" bits) will be sent to the output. I have kept flipper
to have a probability of flipping any single bit of less than 1%.
One will only be able to either detect up to two flipped bits in the encoded word,
or to correct a single flipped bit in the encoded word. All the programs are written to
get all input from stdin and to send all output to stdout.
By doing this, yoneou can run each command separately or you can "pipe" them together.

Overall the development was procedural and few logical problems which came 
on the way got resolved with testing and passing hardcoding and later 
replacing them with variables along the way. 

Error Mechanism was gradually added although command line specification and
incorrect or incomplete command implementation was added to the program in
the end phase of the development.

-------------------------------------------------------------------------------
MANUAL EXECUTION OF CODE
$ g++ -o ./encode | ./flipper | ./decode 

OUTPUT REDERCTION
$ g++ -o ./encode < Input.txt | ./flipper | ./decode > Output.txt

-------------------------------------------------------------------------------
MAKE FILE
Instructions :
Type gmakemake > Makefile inside Project directory.
Make sure the Project houses all the required files to be compiled.
 
$ gmakemake > Makefile
pico Makefile :

Now run make
$ make

output generated.
-------------------------------------------------------------------------------
Version Controlling 
I used RCS version controlling. This is what I did check in and check out files.

I used this command to check in my versions.

//Make an RCS directory to store the checked in files
$ mkdir RCS

$ ci encode.cpp encode.h flipper.cpp flipper.h decode.cpp decode.h

>> Enter Comments and Lock with a single '.'
>> .
Done
Revision Version Locked


I used this command to check out my version.
It used to revert to the last version I had checked in.

$ co -l encode.cpp encode.h flipper.cpp flipper.h decode.cpp decode.h

Unlock the version.
Lock it for others to use.

If I checked it in with the help of ci command i used to get saved as my most recent version.

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

Test Cases Delivered with Output Redirection.

Test Case 1:

$ ./encode < Input.txt | ./flipper | ./decode > Output.txt


$ diff Input.txt Output.txt >> readme.txt

< This limitation of IPv4 stimulated the development of IPv6 in the 1990s, which has been in commercial deployment since 2006.
< IPv4 reserves special address blocks for private networks (~18 million addresses) and multicast addresses (~270 million addresses).
\ No newline at end of file

-------------------------------------------------------------------------------
Test Case 2:

$ ./encode < Input.txt | ./flipper | ./decode > Output.txt


$ diff Input.txt Output.txt >> readme.txt

END OF FILE2,3d1
5d4
< Network address translation has serious drawbacks in terms of the quality of Internet connectivity and requires careful attention to the details of its implementation. In particular, all types of NAT break the originally envisioned model of IP end-to-end connectivity across the Internet and NAPT makes it difficult for systems behind a NAT to accept incoming communications. As a result, NAT traversal methods have been devised to alleviate the issues encountered.
\ No newline at end of file
-------------------------------------------------------------------------------

Test Case 3:

$ ./encode < Input.txt | ./flipper | ./decode > Output.txt


$ diff Input.txt Output.txt >> readme.txt

4,12d3
< [edit]Address depletion
< 
< While the primary reason for IPv4 address exhaustion is insufficient design capacity of the original Internet infrastructure, several additional driving factors have aggravated the shortcomings. Each of them increased the demand on the limited supply of addresses, often in ways unanticipated by the original designers of the network.
< Mobile devices
< As IPv4 increasingly became the de facto standard for networked digital communication and the cost of embedding substantial computing power into hand-held devices dropped, mobile phones have become viable Internet hosts. New specifications of 4G devices require IPv6 addressing.
< Always-on connections
< Throughout the 1990s, the predominant mode of consumer Internet access was telephone modem dial-up. The rapid growth of the dial-up networks increased address consumption rates, although it was common that the modem pools, and as a result, the pool of assigned IP addresses, were shared amongst a larger customer base. By 2007, however, broadband Internet access had begun to exceed 50% penetration in many markets.[12] Broadband connections are always active, as the gateway devices (routers, broadband modems) are rarely turned off, so that the address uptake by Internet service providers continued at an accelerating pace.
< Internet demographics
< There are hundreds of millions of households in the developed world. In 1990, only a small fraction of these had Internet connectivity. Just 15 years later, almost half of them had persistent broadband connections.[13] The many new Internet users in countries such as China and India are also driving address exhaustion.
\ No newline at end of file

-------------------------------------------------------------------------------
Test Case 4:

$ ./encode < Input.txt | ./flipper | ./decode > Output.txt


$ diff Input.txt Output.txt >> readme.txt

2,22d1
< However, many areas still remain without high speed Internet despite the eagerness of potential customers. This can be attributed to population, location, or sometimes ISPs' lack of interest due to little chance of profitability and high costs to build the required infrastructure. Some dial-up ISPs have responded to the increased competition by lowering their rates and making dial-up an attractive option for those who merely want email access or basic web browsing.[3][4]
< [edit]Recession and its effect on service
< News reports in 2009 noted a resurgence of dial-up access in the U.S. resulting from a recessionary economy, as a more affordable way of accessing the Internet.[5][6][7] AOL added 200,000 dial-up customers in 2011. The average monthly price of dial-up Internet is $22, compared to $37 for broadband, according to the FCC.[2]
< Certainly high-speed DSL and Cable are available without local phone service, but the cost of this "naked" service is noticeably higher. AT&T offers basic DSL ("Direct Express") without a phone line for $24.95/month,[8] potentially negating any savings from canceling the phone service. Cable companies do not financially penalize a subscriber for not having a local phone; however cable Internet services are usually more expensive if the customer does not subscribe to their television services.
< Social networking sites such as Facebook and Twitter feature mobile editions with limited graphics and reduced functionality, designed for slow Internet connections on mobile devices. These cut-down websites will also perform well on a PC or netbook with a dial-up connection, making modern social networking possible through traditional dial-up Internet access. The affordability of dial-up Internet (and low-end PCs such as netbooks) makes this one viable option for social networking in a recessionary economy.
< [edit]Performance
< 
< 
< 
< An example handshake of a dial-up modem
< 
< "Dial up modem noises"
< MENU0:00
< Typical noises of dial-up modem while a modem is establishing connection with a local ISP-server in order to get access to the public Internet.
< Problems listening to this file? See media help.
< Modern dial-up modems typically have a maximum theoretical transfer speed of 56 kbit/s (using the V.90 or V.92 protocol), although in most cases 40–50 kbit/s is the norm. Factors such as phone line noise as well as the quality of the modem itself play a large part in determining connection speeds.
< Some connections may be as low as 20 kbit/s in extremely "noisy" environments, such as in a hotel room where the phone line is shared with many extensions, or in a rural area, many miles from the phone exchange. Other things such as long loops, loading coils, pair gain, electric fences (usually in rural locations), and digital loop carriers can also cripple connections to 20 kbit/s or lower.
< Dial-up connections usually have latency as high as 300 ms or even more; this is longer than for many forms of broadband, such as cable or DSL, but typically less than satellite connections. Longer latency can make online gaming or video conferencing difficult, if not impossible. First-person shooter style games are the most sensitive to latency, making playing them impractical on dial-up.
< Many modern video games do not even include the option to use dial-up. However, some games such as Everquest, Red Faction, Star Wars: Galaxies, Warcraft 3, Final Fantasy XI, Phantasy Star Online, Guild Wars, Unreal Tournament, Halo: Combat Evolved, Audition, Quake 3: Arena, and Ragnarok Online, are capable of running on 56k dial-up.
< An increasing amount of Internet content such as streaming media will not work at dial-up speeds.
< Analog telephone lines are digitally switched and transported inside a Digital Signal 0 once reaching the telephone company's equipment. Digital Signal 0 is 64 kbit/s; therefore a 56 kbit/s connection is the highest that will ever be possible with analog phone lines.
\ No newline at end of file

-------------------------------------------------------------------------------
END OF FILE