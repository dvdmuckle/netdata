<!--
title: "Install Netdata on macOS"
custom_edit_url: https://github.com/netdata/netdata/edit/master/packaging/installer/methods/macos.md
-->

# Install Netdata on macOS

Netdata works on macOS, albeit with some limitations. 
The number of charts displaying system metrics is limited, but you can use any of Netdata's [external plugins](/collectors/plugins.d/README.md) to monitor any services you might have installed on your macOS system. 
You could also use a macOS system as the parent node in a [streaming configuration](/streaming/README.md).

You can install Netdata in one of the three following ways: 

- **[Install Netdata with the our automatic one-line installation script (recommended)](#install-netdata-with-our-automatic-one-line-installation-script)**, 
- [Install Netdata via Homebrew](#install-netdata-with-the-homebrew-package)
- [Install Netdata from source](#install-netdata-from-source)

Each of these installation option requires [Homebrew](https://brew.sh/) for handling dependencies. 

> The Netdata Homebrew package is community-created and -maintained.
> Community-maintained packages _may_ receive support from Netdata, but are only a best-effort affair. Learn more about [Netdata's platform support policy](/packaging/platform_support).

## Install Netdata with our automatic one-line installation script

**Local Netdata Agent installation**
To install Netdata using our automatic [kickstart](/packaging/installer/README.md#automatic-one-line-installation-script) open a new terminal and run:

```bash
curl https://my-netdata.io/kickstart.sh > /tmp/netdata-kickstart.sh && sh /tmp/netdata-kickstart.sh
```
The Netdata Agent is be installed under `/usr/local/netdata`. Dependencies are handled via Homebrew.

**Automatically connect to Netdata Cloud during installation**
<!-- Potential reuse: https://learn.netdata.cloud/docs/agent/claim#connect-an-agent-running-in-macos-->
<!--Potential reuse https://learn.netdata.cloud/docs/agent/packaging/installer/methods/kickstart#connect-node-to-netdata-cloud-during-installation The following information is copied from this link.-->

The `kickstart.sh` script accepts additional parameters to automatically [connect](/claim/README.md) your node to Netdata
Cloud immediately after installation. Find the `token` and `rooms` strings by [signing in to Netdata
Cloud](https://app.netdata.cloud/sign-in?cloudRoute=/spaces), then clicking on **Connect Nodes** in the [Spaces management
area](https://learn.netdata.cloud/docs/cloud/spaces#manage-spaces).

- `--claim-token`: Specify a unique claiming token associated with your Space in Netdata Cloud to be used to connect to the node
  after the install.
- `--claim-rooms`: Specify a comma-separated list of tokens for each War Room this node should appear in.
- `--claim-proxy`: Specify a proxy to use when connecting to the cloud in the form of `http://[user:pass@]host:ip` for an HTTP(S) proxy.
  See [connecting through a proxy](/claim/README.md#connect-through-a-proxy) for details.
- `--claim-url`: Specify a URL to use when connecting to the cloud. Defaults to `https://app.netdata.cloud`.

For example: 
```bash
curl https://my-netdata.io/kickstart.sh > /tmp/netdata-kickstart.sh && sh /tmp/netdata-kickstart.sh --install /usr/local/ --claim-token TOKEN --claim-rooms ROOM1,ROOM2 --claim-url https://app.netdata.cloud
```
The Netdata Agent is installed under `/usr/local/netdata` on your machine. Your machine will also show up as a node in your Netdata Cloud.

If you experience issues while claiming your node, follow the steps in our [Troubleshooting](claim/README.md#troubleshooting) documentation.
## Install Netdata via Homebrew

To install Netdata and all its dependencies, run Homebrew using the following command: 

```sh
brew install netdata
```
Homebrew will place your Netdata configuration directory at `/usr/local/etc/netdata/`. 

Use the `edit-config` script and the files in this directory to configure Netdata. For reference, you can find stock configuration files at `/usr/local/Cellar/netdata/{NETDATA_VERSION}/lib/netdata/conf.d/`.

Skip on ahead to the [What's next?](#whats-next) section to find links to helpful post-installation guides.

## Install Netdata from source

We don't recommend installing Netdata from source on macOS, as it can be difficult to configure and install dependencies manually.

1. Open your terminal of choice and install the Xcode development packages:

   ```bash
   xcode-select --install
   ```

2. Click **Install** on the Software Update popup window that appears. 
3. Use the same terminal session to install some of Netdata's prerequisites using Homebrew. If you don't want to use [Netdata Cloud](https://learn.netdata.cloud/docs/cloud/), you can omit `cmake`.

   ```bash
   brew install ossp-uuid autoconf automake pkg-config libuv lz4 json-c openssl libtool cmake
   ```
   
4. Download Netdata from our GitHub repository:

   ```bash
   git clone https://github.com/netdata/netdata.git --recursive
   ```

5. `cd` into the newly-created directory and then start the installer script:

   ```bash
   cd netdata/
   sudo ./netdata-installer.sh --install /usr/local
   ```

> Your Netdata configuration directory will be at `/usr/local/netdata/`. 
> Your stock configuration directory will be at `/usr/local/lib/netdata/conf.d/`.
> The installer will also install a startup plist to start Netdata when your macOS system boots.

## What's next?

When you're finished with installation, check out our [single-node](/docs/quickstart/single-node.md) or
[infrastructure](/docs/quickstart/infrastructure.md) monitoring quickstart guides based on your use case.

Or, skip straight to [configuring the Netdata Agent](/docs/configure/nodes.md).


[![analytics](https://www.google-analytics.com/collect?v=1&aip=1&t=pageview&_s=1&ds=github&dr=https%3A%2F%2Fgithub.com%2Fnetdata%2Fnetdata&dl=https%3A%2F%2Fmy-netdata.io%2Fgithub%2Fpackaging%2Finstaller%2Fmethods%2Fmacos&_u=MAC~&cid=5792dfd7-8dc4-476b-af31-da2fdb9f93d2&tid=UA-64295674-3)](<>)
