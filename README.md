Jellyfish is a Linux based userland gpu rootkit proof of concept project utilizing the LD_PRELOAD technique from Jynx to hook 
system calls and OpenCL to interact with gpu. Code currently supports Nvidia and AMD graphics cards.

Advantages of gpu stored memory:
No gpu malware analysis tools available on web.
Can snoop on cpu host memory via DMA.
gpu can be used for fast/swift mathematical calculations like xor'ing or parsing.

Requirements for use:
Have OpenCL drivers/icds installed.
Nvidia or AMD.
Change line 103 in rootkit/kit.c to server ip you want to monitor gpu client from.

Disclaimer:
Educational purposes only; authors of this project/demonstration are in no way, shape or form responsible for what you may use this
for whether illegal or not.
