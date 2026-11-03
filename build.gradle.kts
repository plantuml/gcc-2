plugins {
	java
	id("org.teavm") version "0.16.0"
}

repositories {
	mavenCentral()
}

tasks.withType<JavaCompile> {
	options.release.set(17)
}

teavm {
	c {
		mainClass.set("Hello")
		obfuscated.set(false)
		// default heap settings of TeaVM (1 MB to 16 MB)
	}
}
