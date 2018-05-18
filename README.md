# Navisens IndoorLocation Provider for iOS

IndoorLocation Provider using MotionDNA SDK from [Navisens](https://www.navisens.com). Track phone motion using the built-in accelerometers and gyroscopes.

From the moment that you have an initial position provided by another provider (QR-Code, iBeacon, Wifi, ... ), you can use this provider to extrapolate the position based on the phone mouvements.

This provider needs to subscribe to a source IndoorLocation provider. Each time the source provider sends a new location, the Navisens provider is reset and will restart from that position to give position updates based on motion.

To use this module, sign up and get your developer key at [https://www.navisens.com]().

## Use

Instantiate the provider with an IndoorLocationProvider as source provider and your Navisens Developper Key.
```
self.provider = [[ILNavisensIndoorLocationProvider alloc] initWithSourceProvider:self.ILManualProvider navisensKey:@"<YOUR NAVISENS KEY>"];
```

Set the provider in your Mapwize SDK:

```
[self.mapwizePlugin setIndoorLocationProvider:self.navisensIndoorLocationProvider];
```

## Demo app

A simple demo application to test the provider is available in the /navisens-indoor-location-provider-ios directory.

You will need to set your credentials in NavisensIndoorLocationProviderDemoApplication and MapActivity.

A sample key is provided for Mapwize. Please note that this keys can only be used for testing purposes, with very limited traffic, and cannot be used in production. Get your own key from [mapwize.io](https://www.mapwize.io). Free accounts are available.

To initialize the position, simply click on the map. The move around and see the position moving.

## Contribute

Contributions are welcome. We will be happy to review your PR.

## Support

For any support with this provider, please do not hesitate to contact [support@mapwize.io](mailto:support@mapwize.io)

## License

MIT
