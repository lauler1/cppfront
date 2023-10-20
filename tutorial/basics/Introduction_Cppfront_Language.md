# Introduction to Cppfront Language


Back to Tutorial [home](../readme.md)

Back to the Chapter [Overview](Overview.md)

## **Diving into the Cppfront Evolution**

As the programming landscape constantly evolves, the software industry is abuzz with efforts to advance C++. Numerous experiments are being conducted to enhance C++ and push its boundaries further. The core ambition here is not to diverge and embrace a new language, but to refine and fortify our skills in C++ itself. The goal is to foster innovations that enhance our proficiency as C++ developers, rather than shifting our focus to a different programming language.

It's evident that Cppfront, an outcome of these evolutionary efforts, holds immense potential. However, the realm of Cppfront is still uncharted for many due to the lack of comprehensive tutorials. While languages like Carbon are gaining traction through quality educational content, Cppfront remains somewhat overshadowed. The silver lining is the seamless interoperability Cppfront boasts with C++. This makes it approachable for enthusiasts keen on experimenting, although it's worth noting that it's still in its nascent stage for production use.

For those interested in its progression, Herb Sutter's GitHub repository offers a transparent view of Cppfront's ongoing development, milestones, and roadmap. It's crucial to be aware that while many features have been introduced, some are still in the pipeline, and existing ones might undergo refinements.

This tutorial is crafted to fill the educational void for Cppfront. ==As the language grows, this tutorial will too.== The primary objective is to elucidate C++'s vital concepts, as reflected in Cppfront's syntax. ==If Cppfront doesn't have a unique style, we'll use modern C++ methods. Whenever Cppfront gets new features, we'll update this guide.==

It's worth highlighting that Cppfront thrives on modern C++ principles and mandates compilation using the C++20 option.

To all budding Cppfront enthusiasts, this tutorial is your compass. Embark on this journey to gain insights into Cppfront's origins, its objectives, and its esteemed place in the dynamic world of programming languages. Let's explore together!

### Cppfront and Cpp2

Throughout this tutorial, you might encounter the term **Cpp2** used interchangeably with **Cppfront**. While Cppfront denotes the entire initiative, encompassing its compiler, Cpp2 is the novel syntax introduced by Cppfront, also known as syntax2. It is typically contrasted with the traditional C++ syntax, labeled as Cpp1. Throughout this tutorial, both terms might be employed to discuss the syntactical elements of the experiment. Notably, files using the Cpp2 syntax bear the `.cpp2` extension.

## **Reimagining C++ with Cppfront**

**Striving for Compatibility:** 
The idea here is simple: What if we could advance C++ while ensuring backwards compatibility? It's like having your cake and eating it too.

**Understanding the Origins:**
- **Bjarne Stroustrup's Vision:** Stroustrup has always sought to streamline C++. Back in 1994, he mentioned, "Inside C++, there's a much smaller and cleaner language trying to emerge." Fast forward to 2007, he envisioned a C++ that was around 10% of its size but was more generalized and less complex.
  
- **Safety through the Years:** The evolution of C++ has been marked by a drive towards ensuring safety:
  - *Type Safety:* Highlighted in CppCon 2021
  - *Bounds Safety*
  - *Lifetime Safety:* Discussed at CppCon 2015
  - *Initialization Safety:* A focal point of CppCon 2020
  
- **Simplifying C++:** Examples of this were presented at CppCon 2020. The idea has always been to refactor C++ into a language with fewer but more potent and versatile features. From 2015-16, there was a push to design this simpler C++ language. By 2016, efforts were being made to present parts of this design as separate proposals for a Syntax 1.

- **Herb Sutter's Proposals:** Sutter has been instrumental in suggesting improvements to C++ through several proposals, including the ones addressing lifetime safety, consistent comparisons, generative C++, deterministic exceptions, parameter passing, and pattern matching.

**Bjarne Stroustrup & the Evolution from C:**
- Stroustrup aimed to address C's limitations by developing “C with Classes” with specific goals:
  1. **Value:** To address C's lack of abstraction.
  2. **Availability:** Make it as ubiquitous as C, ensuring it works seamlessly with existing tools.
  3. **Compatibility:** Ensure full interoperation with C. 
- He achieved this vision with "cfront", a C++ to C compiler.

**Goals & Purpose of Cppfront:**
- The evolution from C++ to Cppfront mirrors Stroustrup's journey with C. With Cppfront, we can:
  1. **Value:** Address contemporary C++ issues, especially around safety, simplicity, and toolability.
  2. **Availability:** Make Cppfront as omnipresent as C++, ensuring it integrates with current systems.
  3. **Compatibility:** Ensure a seamless blend with the original C++ syntax and C.
- The objective is clear: Reduce complexity by 10×, enhance safety by 50×, improve toolability by 10×, and ensure C++ remains a dominant force for decades to come.

**Cppfront in the Programming Landscape:**
- Cppfront is a modern take on C++, with cleaner syntax and better safety features. While languages like Rust emphasize memory safety, Cppfront bridges the gap between classic C++ and modern programming paradigms.
- Unlike entirely new languages like Google's Carbon or Microsoft's Verona, Cppfront enhances C++ through a new syntax. It's akin to TypeScript's relationship with JavaScript, capitalizing on existing C++ ecosystems for easier adoption.
- In essence, Cppfront evolves C++ to modern standards, respects its legacy, and addresses its historical challenges, especially concerning safety and modern constructs.

**Clarifications:**
- "50× safer" translates to a staggering 98% reduction in Common Vulnerabilities and Exposures (CVEs) and related bugs.
- "10× simpler" means that C++ courses and literature can reduce guidance by 90%.

**Cppfront's Approach:**
- Embrace the zero-overhead principle for backward source compatibility, ensuring users only pay for what they use.
- Revitalize C++ itself.
- Make C++ guidelines and modules the default.
- Retain the robust C++ ecosystem and compatibility.

## Tutorial Design and Potential Impact

The tutorial's structure embodies a holistic educational philosophy. Ranging from fundamental to intricate subjects, it delves deep into both core programming principles and cppfront's unique attributes. By drawing parallels between cppfront and traditional C++ concepts, the tutorial may facilitate a swift adoption process. This method could prove instrumental, particularly for developers aiming to bridge their established C++ expertise with the emerging cppfront paradigm.

## Next

To the [Next](Cppfront_VS_Rust.md) Chapter. {style=text-align:center}

Back to Tutorial [home](../readme.md)

Back to the Chapter [Overview](Overview.md)