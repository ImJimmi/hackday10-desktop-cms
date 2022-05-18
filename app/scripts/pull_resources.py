import argparse
import boto3
from botocore.client import Config
from dotenv import load_dotenv
import os
from pprint import pprint


def get_cli_args():
    parser = argparse.ArgumentParser()

    parser.add_argument('--access_key', type=str)
    parser.add_argument('--secret_key', type=str)
    parser.add_argument('--repo_directory', type=str)

    return parser.parse_args()


def get_access_key():
    key = os.getenv('aws_access_key_id')

    if key is not None:
        return key

    args = get_cli_args()

    try:
        return args.access_key
    except:
        pass

    return input('AWS Access Key: ')


def get_secret_key():
    key = os.getenv('aws_secret_access_key')

    if key is not None:
        return key

    args = get_cli_args()

    try:
        return args.secret_key
    except:
        pass

    return input('AWS Secret Key: ')


def create_parameters():
    load_dotenv()

    return {
        'bucket': 'hackday10.desktop.cms',
        'region': 'eu-west-2',
        'access_key': get_access_key(),
        'secret_key': get_secret_key(),
    }


def create_client(parameters):
    return boto3.client(
        's3',
        config=Config(s3={
            'addressing_style': 'path'
        }),
        region_name=parameters['region'],
        aws_access_key_id=parameters['access_key'],
        aws_secret_access_key=parameters['secret_key']
    )


if __name__ == '__main__':
    parameters = create_parameters()
    s3_client = create_client(parameters)

    response = s3_client.list_objects_v2(Bucket=parameters['bucket'])

    repo_dir = get_cli_args().repo_directory

    for object in response['Contents']:
        object_key = object['Key']
        destination_file = os.path.join(repo_dir,
                                        'resources',
                                        object_key)

        print('Downloading "' + object_key +
              '" to "' + destination_file + '"...')

        if not os.path.exists(destination_file):
            os.makedirs(os.path.dirname(destination_file))

        with open(destination_file, 'wb+') as file:
            s3_client.download_file(
                parameters['bucket'],
                object_key,
                file.name
            )
